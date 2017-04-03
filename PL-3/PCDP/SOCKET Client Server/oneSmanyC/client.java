import java.io.*;
import java.net.*;
import java.util.Scanner;

public class client {
	public static void main(String[] args) {
		try{
			Socket s = new Socket("localhost",6665);
			PrintStream ps = new PrintStream(s.getOutputStream());
			ps.println("Hi Mr. Server!!");
			BufferedReader dis = new BufferedReader(new InputStreamReader(s.getInputStream()));
			String reply = dis.readLine();
			System.out.println("Reply from Server:"+reply);
			System.out.println("Enter Reply:");
			Scanner sc = new Scanner(System.in);
			reply = sc.nextLine();
			ps.println(reply);
		}catch(Exception e){System.out.println(e);}
	}
}

