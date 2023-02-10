import socket


server_address_port = ("172.30.114.207", 8888)
buffer_size = 1024


# create a udp socket at client side
udp_client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)


while True:
    message_from_client = input("message to send to the server: ")

    bytes_to_send = str.encode(message_from_client)

    # send to server using created udp socket
    udp_client_socket.sendto(bytes_to_send, server_address_port)

    message_from_server = udp_client_socket.recvfrom(buffer_size)

    message = f"Message from Server {message_from_server[0]}"

    print(message)
