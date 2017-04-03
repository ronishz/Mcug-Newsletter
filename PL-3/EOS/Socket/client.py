import socket

s=socket.socket()
host=socket.gethostname()
port=12345
s.connect(("192.168.9.10",port))

k=s.recv(1024)
print k
n=raw_input()
s.send(n)

print("Client sending filename..")

l=s.recv(1024)

f=open("new.txt","w")
f.write(l)

print("File received from server : ")

print l

s.close()
