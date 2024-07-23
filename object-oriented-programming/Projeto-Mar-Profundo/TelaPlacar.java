

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.EventQueue;
import java.awt.Font;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.util.regex.Pattern;
import java.awt.event.ActionEvent;

public class TelaPlacar extends JFrame {

	private JPanel contentPane;
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					TelaPlacar frame = new TelaPlacar();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	//Cria a aplicação
	public TelaPlacar() {
		String nomes[] = Arquivos.lerPlacar();
		String nomePontos[] = nomes[0].split(Pattern.quote(",")); //pegar os nomes e separar
		
		initialize(nomePontos);
	}
	
	
	//Create the frame.
	public void initialize(String nomePontos[]) {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 800, 600);
		contentPane = new JPanel();
		contentPane.setBackground(Color.BLUE);
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblNewLabel_1_1 = new JLabel("Placar");
		lblNewLabel_1_1.setForeground(Color.WHITE);
		lblNewLabel_1_1.setFont(new Font("Pagul", Font.BOLD, 40));
		lblNewLabel_1_1.setBounds(333, 51, 157, 96);
		contentPane.add(lblNewLabel_1_1);
		
		if(nomePontos.length >= 1) {
			JLabel lbl1Lugar = new JLabel("1. " + nomePontos[0]);
			lbl1Lugar.setForeground(Color.WHITE);
			lbl1Lugar.setFont(new Font("Pagul", Font.BOLD, 25));
			lbl1Lugar.setBounds(260, 145, 309, 30);
			contentPane.add(lbl1Lugar);
		}
			
		if(nomePontos.length >= 2) {
			JLabel lbl2Lugar = new JLabel("2. " + nomePontos[1]);
			lbl2Lugar.setFont(new Font("Pagul", Font.BOLD, 22));
			lbl2Lugar.setForeground(Color.WHITE);
			lbl2Lugar.setBounds(260, 187, 243, 23);
			contentPane.add(lbl2Lugar);
		}
			
		if(nomePontos.length >= 3) {
			JLabel lbl3Lugar = new JLabel("3. " + nomePontos[2]);
			lbl3Lugar.setForeground(Color.WHITE);
			lbl3Lugar.setFont(new Font("Pagul", Font.BOLD, 20));
			lbl3Lugar.setBounds(260, 222, 205, 16);
			contentPane.add(lbl3Lugar);
		}
		
		if(nomePontos.length >= 4) {
			JLabel lbl4Lugar = new JLabel("4. " + nomePontos[3]);
			lbl4Lugar.setForeground(Color.WHITE);
			lbl4Lugar.setFont(new Font("Pagul", Font.BOLD, 18));
			lbl4Lugar.setBounds(260, 250, 205, 16);
			contentPane.add(lbl4Lugar);
		}
		
		if(nomePontos.length >= 5) {
			JLabel lbl5Lugar = new JLabel("5. " + nomePontos[4]);
			lbl5Lugar.setForeground(Color.WHITE);
			lbl5Lugar.setFont(new Font("Pagul", Font.BOLD, 18));
			lbl5Lugar.setBounds(260, 280, 205, 16);
			contentPane.add(lbl5Lugar);
		}
		
		if(nomePontos.length >= 6) {
			JLabel lbl6Lugar = new JLabel("6. " + nomePontos[5]);
			lbl6Lugar.setForeground(Color.WHITE);
			lbl6Lugar.setFont(new Font("Pagul", Font.BOLD, 18));
			lbl6Lugar.setBounds(260, 310, 205, 16);
			contentPane.add(lbl6Lugar);
		}
		
		if(nomePontos.length >= 7) {
			JLabel lbl7Lugar = new JLabel("7. " + nomePontos[6]);
			lbl7Lugar.setForeground(Color.WHITE);
			lbl7Lugar.setFont(new Font("Pagul", Font.BOLD, 18));
			lbl7Lugar.setBounds(260, 340, 205, 16);
			contentPane.add(lbl7Lugar);
		}
		
		if(nomePontos.length >= 8) {
			JLabel lbl8Lugar;
			lbl8Lugar = new JLabel("8. " + nomePontos[7]);
			lbl8Lugar.setForeground(Color.WHITE);
			lbl8Lugar.setFont(new Font("Pagul", Font.BOLD, 18));
			lbl8Lugar.setBounds(260, 370, 205, 16);
			contentPane.add(lbl8Lugar);
		}
		
		if(nomePontos.length >= 9) {
			JLabel lbl9Lugar = new JLabel("9. " + nomePontos[8]);
			lbl9Lugar.setForeground(Color.WHITE);
			lbl9Lugar.setFont(new Font("Pagul", Font.BOLD, 18));
			lbl9Lugar.setBounds(260, 400, 205, 16);
			contentPane.add(lbl9Lugar);
		}
		
		if(nomePontos.length >= 10) {
			JLabel lbl10Lugar = new JLabel("10. " + nomePontos[9]);
			lbl10Lugar.setForeground(Color.WHITE);
			lbl10Lugar.setFont(new Font("Pagul", Font.BOLD, 18));
			lbl10Lugar.setBounds(260, 430, 205, 16);
			contentPane.add(lbl10Lugar);
		}

		
		
		
		JPanel pnlBack = new JPanel();
		pnlBack.setBackground(new Color(5, 61, 87));
		pnlBack.setBounds(200, 0, 400, 600);
		contentPane.add(pnlBack);
		
		JButton btnSair = new JButton("Sair");
		btnSair.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				TelaInicial frame = new TelaInicial();
				frame.setVisible(true);
				dispose();
			}
		});
		btnSair.setForeground(new Color(5, 61, 87));
		btnSair.setFont(new Font("Pagul", Font.BOLD, 20));
		btnSair.setBackground(new Color(211, 214, 216));
		btnSair.setBounds(674, 12, 91, 43);
		contentPane.add(btnSair);
		
		JLabel lblNewLabel = new JLabel("New label");
		lblNewLabel.setIcon(new ImageIcon(TelaPlacar.class.getResource("/view/back2.jpeg")));
		lblNewLabel.setBounds(0, 0, 800, 600);
		contentPane.add(lblNewLabel);
	}
}
