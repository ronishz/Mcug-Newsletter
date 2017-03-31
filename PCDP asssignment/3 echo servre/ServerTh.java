import java.io.*;
import java.net.*;
class ServerTh
{
	public static void main(String args[])
	{
		ServerSocket server;
		int port=Integer.parseInt(args[0]);
		try{
			server=new ServerSocket(port);	
			while(true){
			Socket connection=server.accept();
			ConnectionHandler handler=new ConnectionHandler(connection);
			handler.start();
			} 
		}	
		catch(Exception e){
			System.err.println("Exception Occurs");
		}
		
}
}
class ConnectionHandler extends Thread
{		private Socket connection;
		public ConnectionHandler(Socket connection){
			this.connection=connection;
		}
		
		public void run()
		{
			try{
				System.out.println("Connected...");			
				BufferedReader reader=new BufferedReader(new InputStreamReader(connection.getInputStream()));
				PrintWriter writer=new PrintWriter(connection.getOutputStream());
				System.out.println("ok");				
				String clientName=reader.readLine();
				writer.println("Hello "+clientName);
				writer.flush();			
			}catch(IOException e){}
		}
}
