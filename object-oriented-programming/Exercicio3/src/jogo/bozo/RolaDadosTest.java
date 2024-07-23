package jogo.bozo;

import static org.junit.Assert.*;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class RolaDadosTest {
	private RolaDados dados;
	
	@Before
	public void setUp() throws Exception {
		dados = new RolaDados(5);
	}

	@After
	public void tearDown() throws Exception {
		dados = null;
	}

	@Test
	public void testRolar() {
		int vet[] = dados.rolar();
		int verif = 0;
		
		for(int i = 0; i < vet.length; i++) {
			
			if(vet[i] <= 6 && vet[i] >= 1)
				verif = 1;
			else {
				verif = 0;
				break;
			}
		}
				
		assertEquals(verif, 1);
	}

	@Test
	public void testRolarBooleanArray() {
		int vet1[] = dados.rolar();
		
		int vet2[] = vet1.clone();
		vet2 = dados.rolar(new boolean[] {false, false, false, false, false});
				
		assertArrayEquals(vet1, vet2);
	}
	
	@Test
	public void testRolarBooleanArray2() {
		int vet1[] = dados.rolar();
		int vet2[] = vet1.clone();
		int verif = 0;
		
		vet1 = dados.rolar(new boolean[] {true, true, true, true, true});
	
		for(int i = 0; i < vet1.length; i++) {
			
			if(vet1[i] == vet2[i])
				verif = 1;
			else{
				verif = 0;
				break;
			}
		}
		
		assertEquals(verif, 0);
	}

	@Test
	public void testRolarString1() {
		int vet1[] = dados.rolar();
		
		int vet2[] = vet1.clone();
		vet2 = dados.rolar("");
				
		assertArrayEquals(vet1, vet2);
	}
	
	@Test
	public void testRolarString2() {
		int vet1[] = dados.rolar();
		int vet2[] = vet1.clone();
		int verif = 0;
		
		vet1 = dados.rolar("1 2 3 4 5");
	
		for(int i = 0; i < vet1.length; i++) {
			
			if(vet1[i] == vet2[i])
				verif = 1;
			else{
				verif = 0;
				break;
			}
		}
		
		assertEquals(verif, 0);
	}

	@Test (expected=Exception.class)
	public void testRolarString3() {
		dados.rolar("6 0");
	}

	@Test
	public void testToString() {
		String r = "1       2       3       4       5       \n"
				+ "+-----+ +-----+ +-----+ +-----+ +-----+ \n"
				+ "|     | |    *| |    *| |*   *| |*   *| \n"
				+ "|  *  | |     | |  *  | |     | |  *  | \n"
				+ "|     | |*    | |*    | |*   *| |*   *| \n"
				+ "+-----+ +-----+ +-----+ +-----+ +-----+ \n"
				+ "\n"
				+ "";
		
		dados.dados[0].ladoSuperior = 1;
		dados.dados[1].ladoSuperior = 2;
		dados.dados[2].ladoSuperior = 3; 
		dados.dados[3].ladoSuperior = 4;
		dados.dados[4].ladoSuperior = 5;
			
		assertEquals(r, dados.toString());
	}

}
