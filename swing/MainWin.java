import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.AbstractAction;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.JToolBar;

// This is the remote-controller UI
public class MainWin extends JFrame{
	private static final long serialVersionUID = 2L;
	
	private Client client;
	
	private JTextArea txtArea;
	private JTextField txtfield;
	private JButton describeGrpBtn;
	private JButton describeMediaBtn;
	private JButton playBtn;
	private JButton exitBtn;
	private JMenuBar menubar;
	private JMenu menuActions;
	private JMenu menuData;
	private JToolBar toolbar;

	///
	/// Constructor of the main window of the application 
	///
	public MainWin(Client client){
		this.client = client;
		
 	// creating containers
		menuActions = new JMenu("actions");
		menuData = new JMenu("data");
		menubar = new JMenuBar();
		toolbar = new JToolBar();
		txtArea = new JTextArea(5,60);
		JScrollPane scrollPane = new JScrollPane(txtArea);
		JPanel panel_btn= new JPanel();
		this.setJMenuBar(menubar);
		
		//adding containers to frame
		this.add(toolbar,BorderLayout.NORTH);
		this.add(scrollPane, BorderLayout.CENTER);
		this.add(panel_btn ,BorderLayout.SOUTH);

		
		//Creating actions 
		DescribeGrpAction describeGrpAct = new DescribeGrpAction("describe group");
		DescribeMediaAction describeMediaAct = new DescribeMediaAction("describe media");
		PlayAction playAct = new PlayAction("play");
		ExitAction exitAct = new ExitAction("exit");
		ListGrpAction listGrpAct = new ListGrpAction("list groups");
		ListMediaAction listMediaAct = new ListMediaAction("list media");
		
		//Populating menubar
		menuActions.add(describeGrpAct);
		menuActions.add(describeMediaAct);
		menuActions.add(playAct);
		menuActions.add(exitAct);
		menubar.add(menuActions);
		
		menuData.add(listGrpAct);
		menuData.add(listMediaAct);
		menubar.add(menuData);
		
		//Populating toolbar
		toolbar.add(describeGrpAct);
		toolbar.add(describeMediaAct);
		toolbar.add(playAct);
		toolbar.add(listGrpAct);
		toolbar.add(listMediaAct);
		
		// Creating the buttons
		describeGrpBtn = new JButton("describe group");
		describeMediaBtn = new JButton("describe media");
		playBtn = new JButton("play media");
		exitBtn = new JButton("Exit");
  txtfield = new JTextField("target media or group",30);

		// adding the listeners for the created buttons
		describeGrpBtn.addActionListener(new DescribeGroupListener());
		describeMediaBtn.addActionListener(new DescribeMediaListener());
		playBtn.addActionListener(new PlayListener());
		exitBtn.addActionListener(new ExitListener());
		panel_btn.add(txtfield);
		panel_btn.add(describeGrpBtn);
		panel_btn.add(describeMediaBtn);
		panel_btn.add(playBtn);
		panel_btn.add(exitBtn);

		
		// 
		setDefaultCloseOperation(EXIT_ON_CLOSE);    
		pack();          
		setVisible(true);
	}

	//----------------------------ListenerClasses-------------------------------
	///
	/// Listener associated to the describe Group Button 
	/// reads the targeted group from the text field 
	/// and sends a describe request for this group to the server
	///
	class DescribeGroupListener implements ActionListener {  
		@Override
		public void actionPerformed(ActionEvent e) {
			System.out.println("describeGroupButton pressed");
			String target = txtfield.getText();
			String request = "dgroup " + target;
			String response = client.send(request);
			txtArea.append("\n" + response.replaceAll(";", "\n"));
		}  
	}  
	
	///
	/// Listener associated to the describe Media Button 
	/// reads the targeted media from the text field 
	/// and sends a describe request for this media to the server 
	///
	class DescribeMediaListener implements ActionListener {  
		@Override
		public void actionPerformed(ActionEvent e) {
			System.out.println("describeMediaButton pressed");
			String target = txtfield.getText();
			String request = "dmedia " + target;
			String response = client.send(request);
			txtArea.append("\n" + response.replaceAll(";", "\n"));
		}  
	}  

	///
	/// Listener associated to the play Media Button 
	/// reads the targeted media from the text field 
	/// and sends a play request for this media to the server 
	///
	class PlayListener implements ActionListener {  
		@Override
		public void actionPerformed(ActionEvent e) {
			System.out.println("playBtn pressed");
			String target = txtfield.getText();
			String request = "play " + target;
			String response = client.send(request);
			txtArea.append(response);
		}  
	}  

	class ExitListener implements ActionListener {  
		@Override
		public void actionPerformed(ActionEvent e) {
			System.exit(0);
		}  
	}  

	//-----------------------ActionClasses---------------------------------
	
	///
	/// Action associated to the describe Group Action 
	/// reads the targeted group from the text field 
	/// and sends a describe request for this group to the server
	///
	class DescribeGrpAction extends AbstractAction{
		private static final long serialVersionUID = -4948535457019830998L;
		public DescribeGrpAction(String name){
			super(name);
		}
		@Override
		public void actionPerformed(ActionEvent e) {
			System.out.println("describeGroupAction pressed");
			String target = txtfield.getText();
			String request = "dgroup " + target;
			String response = client.send(request);
			txtArea.append("\n" + response.replaceAll(";", "\n"));
		}

	}
	
	///
	/// Action associated to the describe Media Action
	/// reads the targeted media from the text field 
	/// and sends a describe request for this media to the server 
	///
	class DescribeMediaAction extends AbstractAction{
		private static final long serialVersionUID = -4948535457019830998L;
		public DescribeMediaAction(String name){
			super(name);
		}
		@Override
		public void actionPerformed(ActionEvent e) {
			System.out.println("describeMediaAction pressed");
			String target = txtfield.getText();
			String request = "dmedia " + target;
			String response = client.send(request);
			txtArea.append("\n" + response.replaceAll(";", "\n"));
		}

	}

	///
	/// Listener associated to the play Media Action 
	/// reads the targeted media from the text field 
	/// and sends a play request for this media to the server 
	///
	class PlayAction extends AbstractAction{
		private static final long serialVersionUID = 5573610295557460118L;
		public PlayAction(String name){
			super(name);
		}
		@Override
		public void actionPerformed(ActionEvent e) {
			System.out.println("playAction pressed");
			String target = txtfield.getText();
			String request = "play " + target;
			String response = client.send(request);
			txtArea.append(response);
		}

	}

	class ExitAction extends AbstractAction{
		public ExitAction(String name){
			super(name);
		}
		private static final long serialVersionUID = 4734503961758585571L;
		@Override
		public void actionPerformed(ActionEvent e) {
			System.exit(0);
		}

	}
	
	///
	///  Sends request to the server to list the available groups
	///
	class ListGrpAction extends AbstractAction{
		public ListGrpAction(String name){
			super(name);
		}
		private static final long serialVersionUID = 4734503961758585571L;
		@Override
		public void actionPerformed(ActionEvent e) {
			System.out.println("ListGroupsAction pressed");
			String request = "lgroup";
			String response = client.send(request);
			txtArea.append("\n___Available Groups list:___\n" + response.replaceAll(";", "\n"));
		}

	}

	///
	///  Sends request to the server to list the available media
	///
	class ListMediaAction extends AbstractAction{
		public ListMediaAction(String name){
			super(name);
		}
		private static final long serialVersionUID = 4734503961758585571L;
		@Override
		public void actionPerformed(ActionEvent e) {
			System.out.println("ListGroupsAction pressed");
			String request = "lmedia";
			String response = client.send(request);
			txtArea.append("\n___Available media list:___\n" + response.replaceAll(";", "\n"));
		}

	}

}
