import socket
import struct

HOST = ""
PORT = 8888

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as S:
	s.bind((HOST,PORT))
	s.listen()
	conn, adr = s.accept()
	n = tcp_recieve_int(conn)
	sumArray = 0
	for i in range(n):
		num = tcp_recieve_int(conn)
		sumArray += num
	tcp_send_int(conn, sumArray)
