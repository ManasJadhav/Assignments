import java.util.LinkedList;
import java.util.concurrent.Semaphore;

public class Producer_Consumer {

	static LinkedList<Integer> Buffer;
	int size;
	Semaphore empty;
	Semaphore full;
	Semaphore mutex;
	int consumed = 0;
	
	public Producer_Consumer(int size) {
		this.size = size;
		empty = new Semaphore(size);
		full = new Semaphore(0);
		mutex = new Semaphore(1);	
		Buffer = new LinkedList<>();
	}
	
	public class Producer implements Runnable{
		 
		public Producer() {
			System.out.println("Producer Invoked ...");
		}
		
		public void run() {
			int j = 0;
			do {
				try {
					System.out.println("Producer wants to produce : " + j);
					empty.acquire();
					
				}catch(Exception e) {
					e.printStackTrace();
				}
				
				try {
					mutex.acquire();
					System.out.println("Producer got permision to produce " + j);
				} catch (Exception e) {
					e.printStackTrace();
				}
				
				Buffer.add(j);
				System.out.println("Producer produced item " + j + "\n");
				
				mutex.release();
				full.release();
				
				if(j % 2 == 0) {
					try {
						Thread.sleep(3000);
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
				}
				
				j++;
			}while(j < 10);
		}
	}
	
	public class Consumer implements Runnable{
		public Consumer() { 
			System.out.println("Consumer Invoked...");
		}
		
		public void run() {
			int j = 0; 
			do {
				try {
					System.out.println("Consumer wants to consume : " + (j));
					full.acquire();
				}
				catch(Exception e) {
					e.printStackTrace();
				}
				
				try {
					mutex.acquire();
					System.out.println("Consumer got permision to Consume " + (j));
				} catch (Exception e) {
					e.printStackTrace();
				}
				
				Buffer.removeFirst();
				consumed++;
				System.out.println("Consumer Consumed item " + j + "\n");
				
				mutex.release();
				empty.release();
				
				if(j % 2 == 1) {
					try {
						Thread.sleep(5000);
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
				}
				j++;
				
			} while (j < 10);
		}
	}
	
	public static void main(String[] args) {
		
		Producer_Consumer test = new Producer_Consumer(10);
		
		Thread t1 = new Thread(test.new Producer());
		Thread t2 = new Thread(test.new Consumer());
		
		t2.start();
		t1.start();

	}

}
