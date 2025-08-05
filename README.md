<h1 align="center">Philosophers</h1>
<p align="center"> 
  <img src="https://img.shields.io/badge/grade-100%2F100-green?style=for-the-badge&logo=42&labelColor=gray"/>
</p>

<p align="center"> 
  <a href="https://github.com/pin3dev/42_Cursus/tree/main/library/#03-Philosophers">
    <img src="https://img.shields.io/badge/Threads-blue?style=for-the-badge"/>
    <img src="https://img.shields.io/badge/Mutexes-blue?style=for-the-badge"/>
    <img src="https://img.shields.io/badge/Synchronization-blue?style=for-the-badge"/>
    <img src="https://img.shields.io/badge/Deadlock_Prevention-blue?style=for-the-badge"/>
    <img src="https://img.shields.io/badge/Race_Conditions-blue?style=for-the-badge"/>
  </a>
</p>

<h3>
  <p align="center"> 
    <a href="#introduction">Introduction</a> • 
    <a href="#structure">Structure</a> • 
    <a href="#docs">Docs</a> • 
    <a href="#cloning">Cloning</a> • 
    <a href="#usage">Usage</a> • 
    <a href="#norms">Norms</a> • 
    <a href="#theoretical">Theoretical</a>   
  </p>
</h3>

## 🗣️ Introduction <a id="introduction"></a>

**Philosophers** is a classic computer science problem that demonstrates the challenges of concurrent programming and synchronization. The project simulates the dining philosophers problem, where philosophers sit around a table with forks between them, and they must eat, think, and sleep while avoiding deadlocks and starvation.

The objective of this project is to learn about threading, mutexes, and synchronization mechanisms in concurrent programming. It teaches how to handle shared resources safely and efficiently while preventing race conditions and deadlocks.

## 🧬 Project Structure <a id="structure"></a>

The main components include:

- **Main Program**: Initializes the simulation and creates philosopher threads
- **Philosopher Routines**: Each philosopher follows a cycle of eating, sleeping, and thinking
- **Monitoring System**: Tracks philosopher states and detects death conditions
- **Synchronization**: Uses mutexes to prevent race conditions and ensure thread safety

Each philosopher is represented by a separate thread, and forks are shared resources protected by mutexes.

## 🗃️ Documentation <a id="docs"></a>

For a detailed breakdown of how the project works, please visit the documentation link below:

<p align="center"> 
  <a href="https://github.com/pin3dev/42_Philosophers/wiki">
    <img src="https://img.shields.io/badge/Philosophers_Docs-lightgreen?style=for-the-badge"/>
  </a>
</p>

## 🫥 Cloning the Repository <a id="cloning"></a>

To clone this repository and compile the project, run the following commands:

```bash
git clone https://github.com/pin3dev/42_Philosophers.git
cd 42_Philosophers/philo
```
This will download the project to your local machine. Once inside the `philo` directory, run the provided `Makefile` to compile the project.

## 🕹️ Compilation and Usage <a id="usage"></a>

### Makefile

The project comes with a `Makefile` to automate the compilation process. The Makefile includes the following rules:

- `all`: Compiles the philosopher program.
- `clean`: Removes object files from the `obj/` directory.
- `fclean`: Removes object files, the executable, and the `obj/` directory.
- `re`: Recompiles the entire project from scratch.

To compile the project, run:
```bash
make
```
This will generate the executable `philo`.

### Basic Usage

The program takes the following arguments:
```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

**Parameters:**
- `number_of_philosophers`: Number of philosophers (and forks)
- `time_to_die`: Time in milliseconds before a philosopher dies if they haven't eaten
- `time_to_eat`: Time in milliseconds it takes for a philosopher to eat
- `time_to_sleep`: Time in milliseconds a philosopher spends sleeping
- `number_of_times_each_philosopher_must_eat`: (Optional) Number of times each philosopher must eat before the simulation ends

**Examples:**
```bash
# 5 philosophers, die after 800ms, eat for 200ms, sleep for 200ms
./philo 5 800 200 200

# Same as above, but simulation ends when each philosopher has eaten 7 times
./philo 5 800 200 200 7

# Classic scenario with 4 philosophers
./philo 4 410 200 200
```

### Program Output

The program outputs the state changes of each philosopher:
- `timestamp_in_ms X has taken a fork`
- `timestamp_in_ms X is eating`
- `timestamp_in_ms X is sleeping`
- `timestamp_in_ms X is thinking`
- `timestamp_in_ms X died`

Where `X` is the philosopher number and `timestamp_in_ms` is the time since the simulation started.

## ⚠️ Norms and Guidelines Disclaimer <a id="norms"></a>

This project follows the [**42 School Norm**](https://github.com/pin3dev/42_Cursus/blob/b9cd0fe844ddb441d0b3efb98abcee92aee49535/assets/General/norme.en.pdf) guidelines. Certain decisions in the implementation may seem unconventional, but they were necessary to comply with the strict coding standards enforced by the school.

## 📖 Theoretical Background <a id="theoretical"></a>

All the theoretical material used to study and carry out this project is organized in the tags described at the beginning of this README.
In addition, these materials can be accessed directly via the link provided below.  

<p align="center"> 
  <a href="https://github.com/pin3dev/42_Cursus/tree/main/library/#03-Philosophers">
    <img src="https://img.shields.io/badge/Philosophers_Theory-gray?style=for-the-badge"/>
  </a>
</p>
