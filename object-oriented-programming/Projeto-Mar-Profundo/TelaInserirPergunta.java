import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.EventQueue;
import java.awt.Font;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.UIManager;
import javax.swing.border.EmptyBorder;

public class TelaInserirPergunta extends JFrame {

	private JFrame frame;
	private JTextField txtPergunta;
	private JTextField txtCorreta;
	private JTextField txtErrada1;
	private JTextField txtErrada2;
	private JTextField txtErrada3;
	private JLabel lblNewLabel_2_2;
	private JComboBox<Object> comboBoxCategoria;
	private JButton btnConfirmar;
	private JButton btnSair;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					TelaInserirPergunta window = new TelaInserirPergunta();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	//Cria a aplicação
	public TelaInserirPergunta() {
		initialize();
		
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.setResizable(false);
		frame.setBounds(100, 100, 800, 600);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		
		txtPergunta = new JTextField();
		txtPergunta.setFont(new Font("Dialog", Font.BOLD, 17));
		txtPergunta.setForeground(Color.GRAY);
		txtPergunta.setBackground(Color.WHITE);
		txtPergunta.setBounds(68, 97, 516, 46);
		frame.getContentPane().add(txtPergunta);
		txtPergunta.setColumns(10);
		
		txtCorreta = new JTextField();
		txtCorreta.setFont(new Font("Dialog", Font.BOLD, 17));
		txtCorreta.setForeground(Color.GRAY);
		txtCorreta.setColumns(10);
		txtCorreta.setBackground(Color.WHITE);
		txtCorreta.setBounds(175, 209, 408, 46);
		frame.getContentPane().add(txtCorreta);
		
		txtErrada1 = new JTextField();
		txtErrada1.setFont(new Font("Dialog", Font.BOLD, 17));
		txtErrada1.setForeground(Color.GRAY);
		txtErrada1.setColumns(10);
		txtErrada1.setBackground(Color.WHITE);
		txtErrada1.setBounds(175, 265, 408, 46);
		frame.getContentPane().add(txtErrada1);
		
		txtErrada2 = new JTextField();
		txtErrada2.setFont(new Font("Dialog", Font.BOLD, 17));
		txtErrada2.setForeground(Color.GRAY);
		txtErrada2.setColumns(10);
		txtErrada2.setBackground(Color.WHITE);
		txtErrada2.setBounds(175, 321, 408, 46);
		frame.getContentPane().add(txtErrada2);
		
		txtErrada3 = new JTextField();
		txtErrada3.setFont(new Font("Dialog", Font.BOLD, 17));
		txtErrada3.setForeground(Color.GRAY);
		txtErrada3.setColumns(10);
		txtErrada3.setBackground(Color.WHITE);
		txtErrada3.setBounds(175, 377, 408, 46);
		frame.getContentPane().add(txtErrada3);
		
		JLabel lblNewLabel = new JLabel("Pergunta");
		lblNewLabel.setForeground(Color.WHITE);
		lblNewLabel.setBackground(Color.WHITE);
		lblNewLabel.setFont(new Font("Pagul", Font.BOLD, 30));
		lblNewLabel.setBounds(244, 41, 136, 46);
		frame.getContentPane().add(lblNewLabel);
		
		JLabel lblNewLabel_2 = new JLabel("Categoria");
		lblNewLabel_2.setForeground(Color.WHITE);
		lblNewLabel_2.setFont(new Font("Pagul", Font.BOLD, 30));
		lblNewLabel_2.setBackground(Color.WHITE);
		lblNewLabel_2.setBounds(68, 433, 325, 46);
		frame.getContentPane().add(lblNewLabel_2);
		
		JLabel lblNewLabel_2_1 = new JLabel("Alternativas");
		lblNewLabel_2_1.setForeground(Color.WHITE);
		lblNewLabel_2_1.setFont(new Font("Pagul", Font.BOLD, 30));
		lblNewLabel_2_1.setBackground(Color.WHITE);
		lblNewLabel_2_1.setBounds(233, 153, 174, 46);
		frame.getContentPane().add(lblNewLabel_2_1);
		
		lblNewLabel_2_2 = new JLabel("Correta");
		lblNewLabel_2_2.setForeground(Color.WHITE);
		lblNewLabel_2_2.setFont(new Font("Pagul", Font.BOLD, 25));
		lblNewLabel_2_2.setBackground(Color.WHITE);
		lblNewLabel_2_2.setBounds(68, 209, 97, 46);
		frame.getContentPane().add(lblNewLabel_2_2);
		
		comboBoxCategoria = new JComboBox<Object>();
		comboBoxCategoria.setBackground(Color.WHITE);
		comboBoxCategoria.setFont(new Font("Pagul", Font.BOLD, 12));
		comboBoxCategoria.setBounds(69, 478, 363, 43);
		frame.getContentPane().add(comboBoxCategoria);

		btnConfirmar = new JButton("Confirmar");
		btnConfirmar.setForeground(new Color(5, 61, 87));
		btnConfirmar.setBackground(new Color(211, 214, 216));
		btnConfirmar.setFont(new Font("Pagul", Font.BOLD, 20));
		btnConfirmar.setBounds(442, 478, 142, 43);
		frame.getContentPane().add(btnConfirmar);
		
		btnSair = new JButton("Sair");
		btnSair.setForeground(new Color(5, 61, 87));
		btnSair.setBackground(new Color(211, 214, 216));
		btnSair.setFont(new Font("Pagul", Font.BOLD, 20));
		btnSair.setBounds(669, 47, 91, 43);
		frame.getContentPane().add(btnSair);
		
		JPanel panel = new JPanel();
		panel.setBackground(new Color(5, 61, 87));
		panel.setBorder(UIManager.getBorder("Button.border"));
		panel.setBounds(32, 28, 613, 514);
		frame.getContentPane().add(panel);
		
		JLabel lblNewLabel_1 = new JLabel("New label");
		lblNewLabel_1.setIcon(new ImageIcon(TelaInserirPergunta.class.getResource("/view/back2.jpeg")));
		lblNewLabel_1.setBounds(0, 0, 800, 600);
		frame.getContentPane().add(lblNewLabel_1);

	}
}
