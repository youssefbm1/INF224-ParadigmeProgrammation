public class RemoteController {

	static final String DEFAULT_HOST = "localhost";
	static final int DEFAULT_PORT = 3331;
	  
	private RemoteController() {
	    throw new IllegalAccessError("Utility class");
	  }
	
	public static void main(String[] args) {
		String host = DEFAULT_HOST;
	    int port = DEFAULT_PORT;
	    Client client = null;
	    
	    try {
	      client = new Client(host, port);
	    }
	    catch (Exception e) {
	      System.err.println("Client: Couldn't connect to "+host+":"+port);
	      System.exit(1);
	    }
	    
	    System.out.println("Client connected to "+host+":"+port);

	    MainWin mainwin = new MainWin(client);
		
	}

}
