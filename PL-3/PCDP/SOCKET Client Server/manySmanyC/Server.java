import java.io.*;
import java.util.*;
import java.net.*;

public class Server extends Thread{
	ServerSocket ss;
	public Server(){
		try{
			ss = new ServerSocket(6666);
		}catch(Exception e){}
		
		System.out.println("Server Started...");
		this.start();
	}
	public void run(){
		try{
			int i=0;
			while(true){
				Socket s = ss.accept();
				DataOutputStream dos = new DataOutputStream(s.getOutputStream());
				i++;
				dos.writeUTF("Connection Established...");
				
			}
		}catch(Exception e){}
	}
	public static void main(String args[]){
		new Server();
	}
}
