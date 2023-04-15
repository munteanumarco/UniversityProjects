$(document).ready(function() {
    let score = 0;
    let targetScore = 2;
    let imgSrc = "https://picsum.photos/200";
    let timeMin = 1000; 
    let timeMax = 1100; 
    let displayInterval;
   
    function displayImage() {

      var img = $("<img>");

      img.attr("src", imgSrc + "?random=" + Math.random());
      img.css({
        top: Math.random() * 80 + "vh",
        left: Math.random() * 80 + "vw"
      });

      $(".game-container").append(img);

      setTimeout(function() {
        img.remove();
      }, Math.random() * (timeMax - timeMin) + timeMin);

      img.click(function() {
        score++;
        $("#score").text("Score: " + score);

        if (score >= targetScore) {
          alert("Congratulations, you won!");
          clearInterval(displayInterval);
        }
        img.remove();
      });
    }
    // Set an interval to display a new image every few seconds
    $("#start-game").click(function() {
        $(this).remove();
        displayInterval = setInterval(function() {
            displayImage();
        }, 2000);
    });
  });