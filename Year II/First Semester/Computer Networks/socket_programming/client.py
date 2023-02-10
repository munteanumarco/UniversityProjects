
import socket
import struct

HOST = ""
PORT = 8888

def tcp_send_int(sock, x):
    sock.sendall(struct.pack("!I", x))


def tcp_receive_int(sock):
    x = struct.unpack("!I", sock.recv(4))[0]
    return x

def tcp_send_string(sock, string):
    sock.sendall(string.encode("ascii"))

def tcp_receive_string(sock, size=1024):
    string = sock.recv(size).decode("ascii")
    return string

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    while True:
        n = int(input("Number of chars: "))
        tcp_send_int(s, n)
        for i in range(n):
            c = input(f"charcter {i}: ")
            tcp_send_string(s, c)
        result = tcp_receive_string(s, n)
        print(result)
