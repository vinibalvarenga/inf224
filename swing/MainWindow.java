package swing;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;

public class MainWindow extends JFrame {
    private static final long serialVersionUID = 1L;

    private  Client client; 


    public MainWindow(Client client) {
        super("Main Window");
        this.client = client;

        JTextArea readArea = new JTextArea(20, 50);
        JScrollPane scrollPane = new JScrollPane(readArea);

        JTextField writeArea = new JTextField(50);
        
        JMenuBar menuBar = new JMenuBar();
        JMenu menu = new JMenu("File");
        menu.add(new ButtonAction(writeArea, readArea, client, "create"));
        menu.add(new ButtonAction(writeArea, readArea, client, "add"));
        menu.add(new ButtonAction(writeArea, readArea, client, "delete"));
        menu.add(new ButtonAction(writeArea, readArea, client, "display"));
        menu.add(new ButtonAction(writeArea, readArea, client, "play"));
        menu.addSeparator();
        menu.add(new AbstractAction() {
            private static final long serialVersionUID = 1L;

            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });
        
        menuBar.add(menu);
        setJMenuBar(menuBar);

        JToolBar toolBar = new JToolBar();
        toolBar.add(new ButtonAction(writeArea, readArea, client, "create"));
        toolBar.add(new ButtonAction(writeArea, readArea, client, "add"));
        toolBar.add(new ButtonAction(writeArea, readArea, client, "delete"));
        toolBar.add(new ButtonAction(writeArea, readArea, client, "display"));
        toolBar.add(new ButtonAction(writeArea, readArea, client, "play"));
        toolBar.add(new AbstractAction() {
            private static final long serialVersionUID = 1L;

            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });
        
        add(toolBar, BorderLayout.NORTH);
        
        JPanel readPanel = new JPanel();
        readPanel.setLayout(new BoxLayout(readPanel, BoxLayout.Y_AXIS));
        JLabel readLabel = new JLabel("Read area");
        readPanel.add(readLabel);
        readPanel.add(scrollPane);
        add(readPanel, BorderLayout.CENTER);

        JPanel writePanel = new JPanel();
        writePanel.setLayout(new BoxLayout(writePanel, BoxLayout.Y_AXIS));
        JLabel writeLabel = new JLabel("Write area");
        writePanel.add(writeLabel);
        writePanel.add(writeArea);
        add(writePanel, BorderLayout.SOUTH);

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        pack();
        setVisible(true);
    }

}