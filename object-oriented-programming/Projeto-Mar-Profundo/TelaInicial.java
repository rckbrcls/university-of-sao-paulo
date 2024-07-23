import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import java.awt.SystemColor;
import java.awt.Color;
import javax.swing.JLabel;
import javax.swing.JButton;
import java.awt.Font;
import javax.swing.SwingConstants;
import javax.swing.ImageIcon;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class TelaInicial extends JFrame {

	private JPanel contentPane;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					TelaInicial frame = new TelaInicial();
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
	public TelaInicial() {		
		setResizable(false);
		setBackground(Color.WHITE);
		setTitle("Tela Inicial");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(10, -119, 800, 600);
		contentPane = new JPanel();
		contentPane.setBackground(SystemColor.desktop);
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JButton btnJogar = new JButton("Jogar");
		btnJogar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {				
				TelaNome frame = new TelaNome();
				frame.setVisible(true);
				dispose();
			}
		});
		btnJogar.setForeground(new Color(255, 255, 255));
		btnJogar.setBackground(new Color(0, 128, 128));
		btnJogar.setFont(new Font("Pagul", Font.BOLD, 30));
		btnJogar.setBounds(126, 321, 200, 70);
		contentPane.add(btnJogar);
		
		JButton btnPlacar = new JButton("Placar");
		btnPlacar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				TelaPlacar frame = new TelaPlacar();
				frame.setVisible(true);
				dispose();
				
			}
		});
		btnPlacar.setForeground(new Color(255, 255, 255));
		btnPlacar.setBackground(new Color(0, 128, 128));
		btnPlacar.setFont(new Font("Pagul", Font.BOLD, 30));
		btnPlacar.setBounds(460, 321, 200, 70);
		contentPane.add(btnPlacar);
		
		JLabel lblNewLabel = new JLabel("Mar profundo");
		lblNewLabel.setForeground(new Color(255, 255, 255));
		lblNewLabel.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel.setFont(new Font("Pagul", Font.BOLD, 72));
		lblNewLabel.setBounds(153, 171, 508, 84);
		contentPane.add(lblNewLabel);
		
		JLabel lblNewLabel_1 = new JLabel("Mergulhe no conhecimento");
		lblNewLabel_1.setForeground(new Color(255, 255, 255));
		lblNewLabel_1.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel_1.setFont(new Font("Pagul", Font.BOLD, 20));
		lblNewLabel_1.setBounds(247, 280, 312, 15);
		contentPane.add(lblNewLabel_1);
		
		JLabel lblNewLabel_1_1 = new JLabel("Grupo 12");
		lblNewLabel_1_1.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel_1_1.setForeground(Color.WHITE);
		lblNewLabel_1_1.setFont(new Font("Pagul", Font.BOLD, 16));
		lblNewLabel_1_1.setBounds(247, 138, 312, 15);
		contentPane.add(lblNewLabel_1_1);
		
		JPanel pnlBack = new JPanel();
		pnlBack.setBackground(new Color(5, 61, 87));
		pnlBack.setBounds(0, 125, 800, 296);
		contentPane.add(pnlBack);
		
		JLabel lblNewLabel_2 = new JLabel("Background");
		lblNewLabel_2.setIcon(new ImageIcon(TelaInicial.class.getResource("/view/back.jpg")));
		lblNewLabel_2.setBounds(0, 0, 800, 600);
		contentPane.add(lblNewLabel_2);
	}
}
