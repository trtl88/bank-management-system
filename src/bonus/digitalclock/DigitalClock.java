/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package bonus.digitalclock;

public class DigitalClock {

    private int hours;
    private int minutes;
    private int seconds;

    public DigitalClock(int hours, int minutes, int seconds) {
        this.hours = hours;
        this.minutes = minutes;
        this.seconds = seconds;
    }

    public void increaseSeconds(int secs) {
        if (secs < 0) {
            throw new IllegalArgumentException("-ve Seconds");
        }
        seconds += secs;
        if (seconds >= 60) {
            minutes += seconds / 60;
            seconds = seconds % 60;
        }
        if (minutes >= 60) {
            hours += minutes / 60;
            minutes = minutes % 60;
        }
    }

    public void printTime() {
        System.out.println("H:" + hours + " M: " + minutes + " S:" + seconds);
    }

}
