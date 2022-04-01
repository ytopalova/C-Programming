import java.awt.event.ActionEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import javax.swing.*;
import java.awt.*;
import java.util.Random;

public class HelloJava{
 
    static {
	    System.loadLibrary("MyCPPLibrary0"); 
    }
     
    public static void main(String[] args) {
        HelloJava frame = new HelloJava();
    }

    public HelloJava() { 
        JFrame frame = new JFrame("Hello Java Example"); 
        frame.setSize(450, 250); 

        frame.getContentPane().setLayout(new GridBagLayout()); 
        GridBagConstraints gbc = new GridBagConstraints(); 

        JLabel label = new JLabel("Enter the number to generate:");
        gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.gridx = 1;       
        gbc.gridwidth = 1;   
        gbc.gridy = 0;
        frame.add(label, gbc);

        JTextField textBox = new JTextField(10);
        gbc.gridy = 1;
        gbc.gridx = 1;
        frame.add(textBox, gbc);
        
        JButton goButton = new JButton("Go!"); 
        gbc.gridy = 2;
        gbc.gridx = 1;
        frame.add(goButton, gbc);

        JLabel mean = new JLabel("Mean = "); 
        gbc.gridy = 3;
        gbc.gridx = 0;
        frame.add(mean, gbc);
        
        JLabel stdDev = new JLabel("Standard deviation = "); 
        gbc.gridy = 4;
        gbc.gridx = 0;
        frame.add(stdDev, gbc);

        JTextField meanCalc = new JTextField(10); 
        meanCalc.setEditable(false); 
        gbc.gridy = 3;
        gbc.gridx = 2;
        frame.add(meanCalc, gbc);

        JTextField stdDevCalc = new JTextField(10); 
        stdDevCalc.setEditable(false); 
        gbc.gridy = 4;
        gbc.gridx = 2;
        frame.add(stdDevCalc, gbc);
        
        frame.addWindowListener(new WindowAdapter() { 
            public void windowClosing(WindowEvent e) {
                frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            }
        });

        goButton.addActionListener((ActionEvent ae) -> { 
            int textBoxVal;
            String text = textBox.getText(); 
            textBoxVal = Integer.parseInt(text); 
            int array[] = new int[textBoxVal];
            Random ints = new Random();
            for (int i = 0; i < textBoxVal; i++) { 
                array[i] = ints.nextInt(1000);
            }

            meanCalc.setText(String.format("%.4f", calculateMean(array)));
            stdDevCalc.setText(String.format("%.4f", calculateSTDDev(array)));
        });
        
        frame.setVisible(true); 
    }

    public native double calculateSTDDev(int[] numbers);
    public native double calculateMean(int[] numbers);

}
