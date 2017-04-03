import java.io.*;
import java.net.*;

public class Server{
		public static void main(String args[]){
		try{
			ServerSocket ss;
			ss = new ServerSocket(6665);
			System.out.println("Server Initialized!!!");
			while(true){
				Socket s = ss.accept();
				Connection con = new Connection(s);
			}
		}catch(Exception e){System.out.println(e);}
	}
}

class Connection extends Thread{
	Socket client;
	BufferedReader dis;
	PrintStream ps;
	public Connection(Socket s){
		try{
			client = s;
			System.out.println("Connected to Client:"+client.getInetAddress());
			dis = new BufferedReader(new InputStreamReader(client.getInputStream()));
			ps = new PrintStream(client.getOutputStream());
		}catch(Exception e){}
		this.start();
	}
	public void run(){
		try{
			String mclient = dis.readLine();
			System.out.println("Message Received from Client:"+mclient);
			ps.println("How you doing Mr. Client?");
			mclient = dis.readLine();
			System.out.println("Reply from Client"+client.getInetAddress()+" :"+mclient);
		}catch(Exception e){}
	}
}
