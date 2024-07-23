package jogo.bozo;

import static org.junit.Assert.*;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class PlacarTest {

	private Placar placar;

	@Before
	public void setUp() throws Exception {
		placar = new Placar();
	}

	@After
	public void tearDown() throws Exception {
		placar = null;
	}
	
	@Test (expected=Exception.class)
	public void testAddOcupado1() {
		placar.add(1, new int [] {1, 1, 1, 1, 1});
		placar.add(1, new int [] {1, 1, 1, 1, 1});
	}
	
	@Test (expected=Exception.class)
	public void testAddOcupado2() {
		placar.add(2, new int [] {1, 1, 1, 1, 1});
		placar.add(2, new int [] {1, 1, 1, 1, 1});
	}
	@Test (expected=Exception.class)
	public void testAddOcupado3() {
		placar.add(3, new int [] {1, 1, 1, 1, 1});
		placar.add(3, new int [] {1, 1, 1, 1, 1});
	}
	
	@Test (expected=Exception.class)
	public void testAddOcupado4() {
		placar.add(4, new int [] {1, 1, 1, 1, 1});
		placar.add(4, new int [] {1, 1, 1, 1, 1});
	}
	@Test (expected=Exception.class)
	public void testAddOcupado5() {
		placar.add(5, new int [] {1, 1, 1, 1, 1});
		placar.add(5, new int [] {1, 1, 1, 1, 1});
	}
	
	@Test (expected=Exception.class)
	public void testAddOcupado6() {
		placar.add(6, new int [] {1, 1, 1, 1, 1});
		placar.add(6, new int [] {1, 1, 1, 1, 1});
	}
	@Test (expected=Exception.class)
	public void testAddOcupado7() {
		placar.add(7, new int [] {1, 1, 1, 1, 1});
		placar.add(7, new int [] {1, 1, 1, 1, 1});
	}
	
	@Test (expected=Exception.class)
	public void testAddOcupado8() {
		placar.add(8, new int [] {1, 1, 1, 1, 1});
		placar.add(8, new int [] {1, 1, 1, 1, 1});
	}
	@Test (expected=Exception.class)
	public void testAddOcupado9() {
		placar.add(9, new int [] {1, 1, 1, 1, 1});
		placar.add(9, new int [] {1, 1, 1, 1, 1});
	}
	
	@Test (expected=Exception.class)
	public void testAddOcupado10() {
		placar.add(10, new int [] {1, 1, 1, 1, 1});
		placar.add(10, new int [] {1, 1, 1, 1, 1});
	}
	
	@Test (expected=Exception.class)
	public void testAdd1() {
		placar.add(0, new int [] {1, 1, 1, 1, 1});
	}
	
	@Test (expected=Exception.class)
	public void testAdd2() {
		placar.add(11, new int [] {1, 1, 1, 1, 1});
	}
	
	@Test 
	public void testAdd3() {
		placar.add(1, new int [] {1, 1, 1, 1, 1});
		int test = placar.getScore();
		assertEquals(5, test);
	}
	@Test 
	public void testAdd4() {
		placar.add(2, new int [] {2, 2, 2, 2, 2});
		int test = placar.getScore();
		assertEquals(10, test);
	}
	@Test 
	public void testAdd5() {
		placar.add(3, new int [] {3, 3, 3, 3, 3});
		int test = placar.getScore();
		assertEquals(15, test);
	}
	@Test 
	public void testAdd6() {
		placar.add(4, new int [] {4, 4, 4, 4, 4});
		int test = placar.getScore();
		assertEquals(20, test);
	}
	@Test 
	public void testAdd7() {
		placar.add(5, new int [] {5, 5, 5, 5, 5});
		int test = placar.getScore();
		assertEquals(25, test);
	}
	@Test 
	public void testAdd8() {
		placar.add(6, new int [] {6, 6, 6, 6, 6});
		int test = placar.getScore();
		assertEquals(30, test);
	}
	@Test 
	public void testAdd9() {
		placar.add(7, new int [] {1, 1, 1, 2, 2});
		int test = placar.getScore();
		assertEquals(15, test);
	}
	@Test 
	public void testAdd10() {
		placar.add(8, new int [] {1, 2, 3, 4, 5});
		int test = placar.getScore();
		assertEquals(20, test);
	}
	@Test 
	public void testAdd11() {
		placar.add(9, new int [] {1, 1, 1, 1, 2});
		int test = placar.getScore();
		assertEquals(30, test);
	}
	@Test 
	public void testAdd12() {
		placar.add(10, new int [] {1, 1, 1, 1, 1});
		int test = placar.getScore();
		assertEquals(40, test);
	}

	@Test
	public void testGetScoreVazio() {
		int test = placar.getScore();
		assertEquals(0, test);
	}
	
	@Test
	public void testGetScoreCheio() {
		placar.add(1, new int [] {1, 1, 1, 1, 1});
		placar.add(2, new int [] {2, 2, 2, 2, 2});
		placar.add(3, new int [] {3, 3, 3, 3, 3});
		placar.add(4, new int [] {4, 4, 4, 4, 4});
		placar.add(5, new int [] {5, 5, 5, 5, 5});
		placar.add(6, new int [] {6, 6, 6, 6, 6});
		placar.add(7, new int [] {1, 1, 1, 2, 2});
		placar.add(8, new int [] {1, 2, 3, 4, 5});
		placar.add(9, new int [] {1, 1, 1, 1, 2});
		placar.add(10, new int [] {1, 1, 1, 1, 1});
		int test = placar.getScore();
		assertEquals(210, test);
	}

	@Test
	public void testToString1() {
		String r = "\n\n  (1)   |   (7)   |   (4)  \n---------------------------\n  (2)   |   (8)   |   (5)  \n---------------------------\n  (3)   |   (9)   |   (6)  \n---------------------------\n        |   (10)  |\n        +---------+ \n\n";
		assertEquals(placar.toString(), r);
	}
	@Test
	public void testToString2() {
		placar.add(1, new int [] {1, 1, 1, 1, 1});
		String r = "\n\n   5    |   (7)   |   (4)  \n---------------------------\n  (2)   |   (8)   |   (5)  \n---------------------------\n  (3)   |   (9)   |   (6)  \n---------------------------\n        |   (10)  |\n        +---------+ \n\n";
		assertEquals(placar.toString(), r);
	}
	@Test
	public void testToString3() {
		placar.add(2, new int [] {2, 2, 2, 2, 2});
		String r = "\n\n  (1)   |   (7)   |   (4)  \n---------------------------\n   10    |   (8)   |   (5)  \n---------------------------\n  (3)   |   (9)   |   (6)  \n---------------------------\n        |   (10)  |\n        +---------+ \n\n";
		assertEquals(placar.toString(), r);
	}
	@Test
	public void testToString4() {
		placar.add(3, new int [] {3, 3, 3, 3, 3});
		String r = "\n\n  (1)   |   (7)   |   (4)  \n---------------------------\n  (2)   |   (8)   |   (5)  \n---------------------------\n   15    |   (9)   |   (6)  \n---------------------------\n        |   (10)  |\n        +---------+ \n\n";
		assertEquals(placar.toString(), r);
	}
	@Test
	public void testToString5() {
		placar.add(4, new int [] {4, 4, 4, 4, 4});
		String r = "\n\n  (1)   |   (7)   |    20   \n---------------------------\n  (2)   |   (8)   |   (5)  \n---------------------------\n  (3)   |   (9)   |   (6)  \n---------------------------\n        |   (10)  |\n        +---------+ \n\n";
		assertEquals(placar.toString(), r);
	}
	@Test
	public void testToString6() {
		placar.add(5, new int [] {5, 5, 5, 5, 5});
		String r = "\n\n  (1)   |   (7)   |   (4)  \n---------------------------\n  (2)   |   (8)   |    25   \n---------------------------\n  (3)   |   (9)   |   (6)  \n---------------------------\n        |   (10)  |\n        +---------+ \n\n";
		assertEquals(placar.toString(), r);
	}
	@Test
	public void testToString7() {
		placar.add(6, new int [] {6, 6, 6, 6, 6});
		String r = "\n\n  (1)   |   (7)   |   (4)  \n---------------------------\n  (2)   |   (8)   |   (5)  \n---------------------------\n  (3)   |   (9)   |    30   \n---------------------------\n        |   (10)  |\n        +---------+ \n\n";
		assertEquals(placar.toString(), r);
	}
	@Test
	public void testToString8() {
		placar.add(7, new int [] {1, 1, 1, 2, 2});
		String r = "\n\n  (1)   |    15    |   (4)  \n---------------------------\n  (2)   |   (8)   |   (5)  \n---------------------------\n  (3)   |   (9)   |   (6)  \n---------------------------\n        |   (10)  |\n        +---------+ \n\n";
		assertEquals(placar.toString(), r);
	}
	@Test
	public void testToString9() {
		placar.add(8, new int [] {1, 2, 3, 4, 5});
		String r = "\n\n  (1)   |   (7)   |   (4)  \n---------------------------\n  (2)   |    20    |   (5)  \n---------------------------\n  (3)   |   (9)   |   (6)  \n---------------------------\n        |   (10)  |\n        +---------+ \n\n";
		assertEquals(placar.toString(), r);
	}
	@Test
	public void testToString10() {
		placar.add(9, new int [] {1, 1, 1, 1, 2});
		String r = "\n\n  (1)   |   (7)   |   (4)  \n---------------------------\n  (2)   |   (8)   |   (5)  \n---------------------------\n  (3)   |    30    |   (6)  \n---------------------------\n        |   (10)  |\n        +---------+ \n\n";
		assertEquals(placar.toString(), r);
	}
	@Test
	public void testToString11() {
		placar.add(10, new int [] {1, 1, 1, 1, 1});
		String r = "\n\n  (1)   |   (7)   |   (4)  \n---------------------------\n  (2)   |   (8)   |   (5)  \n---------------------------\n  (3)   |   (9)   |   (6)  \n---------------------------\n      |  40  |\n        +---------+ \n\n";
		assertEquals(placar.toString(), r);
	}
}
