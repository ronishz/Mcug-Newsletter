import java.io.*;
import java.util.*;
import java.net.*;

public class Client{
	public static void main(String args[]){
		Socket s;
		try{
			while(true){
				String ip="";
				System.out.println("Select the Server to Connect:\n1.'172.16.132.110'\n2.'172.16.133.55'");
				Scanner sc = new Scanner(System.in);
				int choice = sc.nextInt();
				if(choice == 1)
					ip = "172.16.132.110";
				else if (choice == 2)
					ip = "172.16.133.55";
				s = new Socket(ip,6666);
				DataInputStream dis = new DataInputStream(s.getInputStream());
				String message = dis.readUTF();
				System.out.println(message);
				int i=1;
				while(i!=0){
					System.out.println("Enter 0 to Exit");

					i = sc.nextInt();
				}
			}
		}catch(Exception e){}
	}
}
