import socket

ip = '192.168.254.200'
port = 80


conn = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

conn.connect((ip,port))

while 1:
    data = input("Send something : ")
    if data == 'q' or data == 'Q':
        break
    else:
        conn.send(data.encode())