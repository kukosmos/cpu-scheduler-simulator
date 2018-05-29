# CPU Scheduler Simulator
Korea Univ. Operating System Term Project  
The program does
1. Simulate CPU scheduling algorithms
2. Analyze turn around time and waiting time
3. Show the gantt chart CPU

## Supported CPU Scheduling Algorithm
* First Come First Served ("fcfs")
* Non-preemptive Shortest Job First ("np_sjf")
* Preemptive Shorted Job First ("p_sjf")
* Non-preemptive Priority ("np_priority")
* Preemptive Priority ("p_priority")
* Round-robin ("rr")
* Non-preemptive Shortest Remain Time First ("np_srtf")
* Preemptive Shortest Remain Time First ("p_srtf")

## Build
```
$ make
```

## Execution
```
Usage: simulator <options> <scheduler options>

options are:
   -h, --help      show the list of options
   -n <int>        number of processes to create (default : 10)
   -tq <int>       size of time quantum of round-robin scheduler (default : 4)

scheduler options are:
   --fcfs           simulate Fisrt Come First Served
   --np-sjf         simulate Non-Preemptive Shortest Job First
   --p-sjf          simulate Preemptive Shortest Job First
   --np-priority    simulate Non-Preemptive Priority
   --p-priority     simulate Preemptive Priority
   --rr             simulate Round Robin
   --np-srtf        simulate Non-Preemptive Shortest Remain Time First
   --p-srtf         simulate Preemptive Shortest Remain Time First
```
For example, to test 5 process with FCFS and round-robin with time quantum of 2
```
$ ./simulator -n 5 -tq 2 --fcfs --rr
```
If you don't specify schduler options, all scheduler algorithms are simulated.

## Clean
```
$ make clean
```