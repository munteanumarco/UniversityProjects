package com.example.subscriptions.controller;

import com.example.subscriptions.dto.MessageDTO;
import com.example.subscriptions.dto.SubscriptionDTO;
import com.example.subscriptions.dto.UserCredentialsDTO;
import com.example.subscriptions.model.Channel;
import com.example.subscriptions.model.Person;
import com.example.subscriptions.repository.ChannelRepository;
import com.example.subscriptions.repository.PersonRepository;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

@RestController
@RequestMapping("/api")
public class ExamController {
    private final PersonRepository personRepository;
    private final ChannelRepository channelRepository;

    public ExamController(PersonRepository personRepository, ChannelRepository channelRepository) {
        this.personRepository = personRepository;
        this.channelRepository = channelRepository;
    }

    @PostMapping("/authenticate")
    public ResponseEntity<?> loginPerson(@RequestBody UserCredentialsDTO loginDTO, HttpServletRequest request) {
        Optional<Person> optionalPerson = this.personRepository.findByName(loginDTO.getName());

        if (optionalPerson.isPresent()) {
            Person person = optionalPerson.get();

            // Create a new session or retrieve the existing one
            HttpSession session = request.getSession(true);
            session.setAttribute("name", person.getName());

            return ResponseEntity
                    .ok(person);
        } else {
            return ResponseEntity
                    .status(HttpStatus.NOT_FOUND)
                    .body(new MessageDTO("Person does not exist"));
        }
    }

    @GetMapping("/channels")
    public ResponseEntity<?> getChannelsByPersonName(@RequestParam(required = true) String ownerName) {
        Optional<Person> optionalPerson = this.personRepository.findByName(ownerName);

        if (optionalPerson.isPresent()) {
            Person person = optionalPerson.get();

            List<Channel> channels = this.channelRepository.findByPersonID(person.getID());

            return ResponseEntity
                    .ok(channels);
        } else {
            return ResponseEntity
                    .status(HttpStatus.NOT_FOUND)
                    .body(new MessageDTO("Owner does not exist"));
        }
    }

    @GetMapping("/myChannels")
    public ResponseEntity<?> getMyChannels(HttpServletRequest request) {
        HttpSession session = request.getSession(false);

        if (session != null) {
            String name = (String) session.getAttribute("name");

            Optional<Person> optionalPerson = this.personRepository.findByName(name);

            if (optionalPerson.isPresent()) {
                Person person = optionalPerson.get();

                List<Channel> channels = new ArrayList<>();
                List<Channel> allChannels = this.channelRepository.findAll();
                for (Channel channel: allChannels) {
                    String[] subscribers = channel.getSubscribers().split(";");
                    for (String subscriber: subscribers) {
                        int subscriberID = Integer.parseInt(subscriber.split("\\.")[0]);
                        if (subscriberID == person.getID()) {
                            channels.add(channel);
                            break;
                        }
                    }
                }

                return ResponseEntity
                        .ok(channels);
            } else {
                return ResponseEntity
                        .status(HttpStatus.NOT_FOUND)
                        .body(new MessageDTO("Owner does not exist"));
            }
        } else {
            return ResponseEntity.badRequest().body(new MessageDTO("No active session"));
        }
    }

    @PostMapping("/subscribe")
    public ResponseEntity<?> subscribeToChannel(@RequestBody SubscriptionDTO subscriptionDTO, HttpServletRequest request) {
        HttpSession session = request.getSession(false);

        if (session != null) {
            String name = (String) session.getAttribute("name");

            Optional<Person> optionalPerson = this.personRepository.findByName(name);

            if (optionalPerson.isPresent()) {
                Person person = optionalPerson.get();

                Channel channel = this.channelRepository.findById(subscriptionDTO.getId()).orElseThrow();
                StringBuilder newSubscribers = new StringBuilder();
                boolean updated = false;
                String[] subscribers = channel.getSubscribers().split(";");
                for (String subscriber: subscribers) {
                    int subscriberID = Integer.parseInt(subscriber.split("\\.")[0]);
                    if (subscriberID == person.getID()) {
                        LocalDate currentDate = LocalDate.now();
                        String updatedSubscription = subscriber.split("\\.")[0] + "." + currentDate + ";";
                        newSubscribers.append(updatedSubscription);
                        updated = true;
                    } else {
                        newSubscribers.append(subscriber + ";");
                    }
                }

                if (!updated) {
                    LocalDate currentDate = LocalDate.now();
                    newSubscribers.append(person.getID().toString() + "." + currentDate);
                }

                String sol = newSubscribers.toString();
                if (sol.endsWith(";")) {
                    sol = sol.substring(0, sol.length() - 1);
                }

                channel.setSubscribers(sol);
                this.channelRepository.save(channel);

                if (updated) {
                    return ResponseEntity.ok(new MessageDTO("Successfully updated subscription"));
                } else {
                    return ResponseEntity.ok(new MessageDTO("Successfully subscribed to the channel"));
                }
            } else {
                return ResponseEntity
                        .status(HttpStatus.NOT_FOUND)
                        .body(new MessageDTO("Owner does not exist"));
            }
        } else {
            return ResponseEntity.badRequest().body(new MessageDTO("No active session"));
        }
    }
}
