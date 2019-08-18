/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package threaddemo;

import java.lang.*;

/**
 *
 * @author hunter
 */
public class ThreadDemo implements Runnable {

    Thread t;
    
    ThreadDemo(){
        
        t = new Thread(this);
        System.out.println("Executing " + t.getName());
        t.start();
        
        if(!t.isInterrupted()){
            t.interrupt();
        }
        try {
            t.join();
        } catch(InterruptedException e) {}
    }
    
    public void run(){
        try {
            while (true){
                Thread.sleep(1000);
            }
        } catch (InterruptedException e) {
            System.out.print(t.getName() + " interrupted:");
            System.out.println(e.toString());
        }
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        new ThreadDemo();
        new ThreadDemo();
    }
    
}
