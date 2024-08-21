import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.EventQueue;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.SwingConstants;

public class TelaNome extends JFrame {

	private JPanel contentPane;
	private JTextField txtNome;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					TelaNome frame = new TelaNome();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public TelaNome() {
		setTitle("Insira seu nome");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		contentPane.setBackground(new Color(5, 61, 87));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblInsiraSeuNome = new JLabel("Insira seu nome");
		lblInsiraSeuNome.setBounds(112, 28, 222, 19);
		lblInsiraSeuNome.setForeground(new Color(255, 255, 255));
		lblInsiraSeuNome.setHorizontalAlignment(SwingConstants.CENTER);
		lblInsiraSeuNome.setFont(new Font("Pagul", Font.BOLD, 24));
		contentPane.add(lblInsiraSeuNome);
		
		txtNome = new JTextField();
		txtNome.setFont(new Font("Pagul", Font.BOLD, 20));
		txtNome.setBounds(112, 92, 222, 36);
		contentPane.add(txtNome);
		txtNome.setColumns(10);
		
		JButton btnJogar = new JButton("Jogar");
		btnJogar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				Placar atual = new Placar(0, txtNome.getText()); //Iniciaremos o placar
				TelaCategoria frame = new TelaCategoria(atual);
				frame.setVisible(true);
				dispose();
			}
		});
		btnJogar.setForeground(new Color(255, 255, 255));
		btnJogar.setBackground(new Color(0, 128, 128));
		btnJogar.setFont(new Font("Pagul", Font.BOLD, 30));
		btnJogar.setBounds(132, 178, 177, 55);
		contentPane.add(btnJogar);
	}
}
