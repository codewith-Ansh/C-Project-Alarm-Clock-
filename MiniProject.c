#include <stdio.h>
#include <time.h>
#include <windows.h>

void playBeepPattern() {
    // Frequency for the beep sound
    int frequency = 1000;  // 1000 Hz is a middle-range beep

    // Duration for beep and gap (in milliseconds)
    int beepDuration = 1000;   // Beep for 1 second
    int gapDuration = 500;     // Gap for 0.5 second

    // Repeat the pattern of beep and gap for 15 seconds
    for (int i = 0; i < 10; i++) { // 10 cycles, each taking 1.5 seconds
        Beep(frequency, beepDuration);  // Beep for 1 second
        Sleep(gapDuration);             // Wait for 0.5 second (gap)
    }
}

int main() {
    int alarmHour, alarmMinute, alarmSecond;

    // Ask the user to set the alarm time
    printf("Set the alarm time (24-hour format):\n");
    printf("Enter hour (0-23): ");
    scanf("%d", &alarmHour);
    printf("Enter minute (0-59): ");
    scanf("%d", &alarmMinute);
    printf("Enter second (0-59): ");
    scanf("%d", &alarmSecond);

    printf("\nAlarm is set for %02d:%02d:%02d.\n", alarmHour, alarmMinute, alarmSecond);

    while (1) {
        // Get the current system time
        time_t now = time(NULL);
        struct tm *current = localtime(&now);

        int currentHour = current->tm_hour;
        int currentMinute = current->tm_min;
        int currentSecond = current->tm_sec;

        // Display current time for feedback
        printf("Current Time: %02d:%02d:%02d\n", currentHour, currentMinute, currentSecond);

        // Check if the current time matches the alarm time
        if (currentHour == alarmHour && currentMinute == alarmMinute && currentSecond == alarmSecond) {
            playBeepPattern(); // Play the beep pattern for 15 seconds
            break;             // Exit the loop after the alarm rings
        }

        // Sleep for a short duration to reduce CPU usage
        Sleep(1000);  // Check every second
    }
    printf("Alarm has ended.\n");
    return 0;
}