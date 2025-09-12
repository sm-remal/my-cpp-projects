// SJF - Algorithm 

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int pid[20], at[20], bt[20], wt[20], tat[20];
    int completed[20] = {0}; 

    // Input
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        cout << "Enter Arrival Time for Process " << pid[i] << ": ";
        cin >> at[i];
        cout << "Enter Burst Time for Process " << pid[i] << ": ";
        cin >> bt[i];
    }

    int currentTime = 0, count = 0;
    float totalWT = 0, totalTAT = 0;

    cout << "\nGantt Chart:\n|";

    // Loop until all processes complete
    while (count < n) {
        int idx = -1;
        int minBT = 999999;

        // Find shortest job among arrived processes
        for (int i = 0; i < n; i++) {
            if (completed[i] == 0 && at[i] <= currentTime && bt[i] < minBT) {
                minBT = bt[i];
                idx = i;
            }
        }

        if (idx == -1) {
            // CPU is idle (no process arrived yet)
            currentTime++;
            continue;
        }

        // Show in Gantt Chart
        cout << " P" << pid[idx] << " |";

        // Calculate times
        wt[idx] = currentTime - at[idx];
        tat[idx] = wt[idx] + bt[idx];

        totalWT += wt[idx];
        totalTAT += tat[idx];

        currentTime += bt[idx];
        completed[idx] = 1;
        count++;
    }

    // Print results
    cout << "\n\nProcess\tAT\tBT\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << pid[i] << "\t" << at[i] << "\t" << bt[i]
             << "\t" << wt[i] << "\t" << tat[i] << "\n";
    }

    cout << "\nAverage Waiting Time = " << totalWT / n;
    cout << "\nAverage Turnaround Time = " << totalTAT / n << endl;

    return 0;
}





// FCFS - Algorithm


#include <iostream>
using namespace std;

struct Process {
    int pid;
    int at;  // Arrival Time
    int bt;  // Burst Time
    int wt;  // Waiting Time
    int tat; // Turnaround Time
};

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    Process p[n];

    // Input Arrival and Burst Times
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        cout << "Enter Arrival Time for Process " << p[i].pid << ": ";
        cin >> p[i].at;
        cout << "Enter Burst Time for Process " << p[i].pid << ": ";
        cin >> p[i].bt;
    }

    // Sort processes by Arrival Time
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].at > p[j].at) {
                swap(p[i], p[j]);
            }
        }
    }

    // Calculate Waiting and Turnaround Time
    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (currentTime < p[i].at) {
            currentTime = p[i].at;
        }
        p[i].wt = currentTime - p[i].at;
        p[i].tat = p[i].wt + p[i].bt;
        currentTime += p[i].bt;
    }

    // Output Table
    float totalWT = 0, totalTAT = 0;
    cout << "\nProcess\tAT\tBT\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << p[i].pid << "\t" << p[i].at << "\t" << p[i].bt << "\t" << p[i].wt << "\t" << p[i].tat << "\n";
        totalWT += p[i].wt;
        totalTAT += p[i].tat;
    }

    cout << "\nAverage Waiting Time = " << totalWT / n;
    cout << "\nAverage Turnaround Time = " << totalTAT / n << endl;

    // Gantt Chart
    cout << "\nProcess execution order (Gantt Chart):\n|";
    for (int i = 0; i < n; i++) {
        cout << " P" << p[i].pid << " |";
    }
    cout << endl;

    return 0;
}