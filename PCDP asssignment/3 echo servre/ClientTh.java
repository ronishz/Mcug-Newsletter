import java.io.*;
import java.net.*;
import java.util.Scanner;
class ClientTh
{
	public static void main(String args[]) throws IOException
	{
		String hostName=args[0];
		int port=Integer.parseInt(args[1]);
		Socket connection;
		try{
			connection=new Socket(hostName,port);
		
		
		System.out.println("Connected...");
		BufferedReader reader=new BufferedReader(new InputStreamReader(connection.getInputStream()));
		PrintWriter writer=new PrintWriter(connection.getOutputStream(),true);
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter Your Name: ");
		String nm=sc.next();
		writer.println(nm);
		String reply=reader.readLine();
		System.out.println("Server reply: "+reply);
		writer.flush();	
	}catch(Exception io1){}
	}
}
