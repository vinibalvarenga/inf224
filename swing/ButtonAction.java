package swing;

import java.awt.event.ActionEvent;

import javax.swing.AbstractAction;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public class ButtonAction extends AbstractAction{
    private static final long serialVersionUID = 1L; 
    private JTextField writeArea; /* The text field where the user will write the request */
    private JTextArea readArea; /* The text area where the server's response will be shown */
    private Client client; 
    private String actionName; /* The name of the action for this button */

    public ButtonAction(JTextField writeArea, JTextArea readArea, Client client, String actionName){
        super(actionName);
        this.writeArea = writeArea;
        this.readArea = readArea;
        this.client = client;
        this.actionName = actionName;
    }

    @Override
    public void actionPerformed(ActionEvent e){
        String request = actionName + " " + writeArea.getText();
        System.out.println("Request: " + request);
        String response = client.send(request);
        System.out.println("Response: " + response);
        readArea.append(response + "\n");
        writeArea.setText("");
    }
}
