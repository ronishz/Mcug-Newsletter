import socket

s=socket.socket()                                                               
host=socket.gethostname()
print host
port=12345
s.bind(("192.168.9.10",port))                                                   
s.listen(5)

print "Connection established"                                                  
while True:
        c,addr=s.accept()
                                                                                
        c.send("1.a.txt\n2.b.txt\n3.c.txt\nEnter name of file:")
    
        print "File name recieved from client : "
        m=c.recv(1024)
        print m
    
        f=open(m,"r")
        l=f.read()
                                                                                
        c.send(l)
        print "File sent."

c.close()
s.close()
 

