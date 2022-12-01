import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.*;

public class Server {

	public static void main(String[] args) {
		ServerSocket server = null;
		int id = 0;
		try{
			server = new ServerSocket(8080);
			server.setReuseAddress(true);			
			System.out.println("Server started...");
			while(true) {
				Socket client = server.accept();
				id++;
				System.out.println("New Client " +id+ " Connected : " + client.getInetAddress().getHostAddress());
				
				ClientHandler newClient = new ClientHandler(client, id);
				
				new Thread(newClient).start();
				
			}
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			if(server != null) {
				try {
					server.close();
					System.out.println("Server Connection Closed!!!");
				} catch (IOException e) {
					System.out.println("Something went wrong while closing server!!!");
					e.printStackTrace();
				}
			}
		}
	}
	
	private static class ClientHandler implements Runnable {
		private final Socket clientSocket;
		private final int id;
		
		public ClientHandler(Socket socket, int id) {
			this.clientSocket = socket;
			this.id = id;
		}
		
		public void run(){
			PrintWriter out = null;
			BufferedReader in = null;
			
			try {
				out = new PrintWriter(clientSocket.getOutputStream(), true);
				in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
				String line;
				while((line = in.readLine()) != null) {
					System.out.println("Client "+ id +" sent message : " + line);
					out.println(line);
				}
			} catch (IOException e) {
				e.printStackTrace();
			}finally {
				try {
					if(out != null) {
						out.close();
					}
					if(in != null) {
						in.close();
					}
					if(clientSocket != null) {
						clientSocket.close();
						System.out.println("Client "+ id +" Quitted");
					}
				}catch (Exception e) {
					System.out.println("Something went wrong while exiting!!!");
					e.printStackTrace();
				}
			}
		}
	}

}