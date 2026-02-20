# Philosophers

*This project has been created as part of the 42 curriculum by mohifdi.*

## Description

The Philosophers project is a classic threading and synchronization problem. Multiple philosophers sit at a round table with a bowl of spaghetti. They alternate between eating, thinking, and sleeping. Each philosopher needs two forks to eat, but there are only as many forks as philosophers. The challenge is to prevent deadlock and ensure no philosopher starves.

This project teaches the fundamentals of:
- Thread creation and management with pthread
- Mutex usage for resource protection
- Race condition prevention
- Deadlock avoidance

## Instructions

### Compilation
```bash
make
```

### Execution
```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

**Arguments:**
- `number_of_philosophers`: Number of philosophers (and forks)
- `time_to_die`: Time in milliseconds until a philosopher dies without eating
- `time_to_eat`: Time in milliseconds a philosopher spends eating
- `time_to_sleep`: Time in milliseconds a philosopher spends sleeping
- `number_of_times_each_philosopher_must_eat`: (Optional) Simulation stops when all philosophers have eaten this many times

**Example:**
```bash
./philo 5 800 200 200
./philo 5 800 200 200 7
```

### Cleanup
```bash
make clean
make fclean
make re    
```

## Features

- Each philosopher is a separate thread
- Forks are protected by mutexes to prevent data races
- Monitor thread checks for philosopher deaths and completion
- Precise timing using gettimeofday()
- Handles edge cases (1 philosopher, death detection, etc.)
- Clean output formatting with timestamps

## Implementation Details

### Architecture
The program uses a data-driven approach with two main structures:
- `t_data`: Global simulation data (timings, flags, mutexes)
- `t_philo`: Individual philosopher data (ID, forks, meal tracking)

### Synchronization Strategy
- **Fork mutexes**: One mutex per fork to prevent simultaneous access
- **Write mutex**: Protects console output from interleaving
- **Meal mutex**: Protects last_meal_time updates
- **Dead mutex**: Protects the death flag

### Death Detection
A dedicated monitor thread continuously checks:
1. Time since each philosopher's last meal
2. Whether all philosophers have eaten enough times (if specified)

### Deadlock Prevention
- Even-numbered philosophers wait 1ms before starting to desynchronize fork access
- Philosophers always take left fork first, then right fork
- Single philosopher case handled specially

## Resources

### Technical Documentation
- [A Simple Guide to "The Dining Philosopher" Problem](https://www.youtube.com/watch?v=Dt51GebwNR0)
- [pthread man pages](https://man7.org/linux/man-pages/man7/pthreads.7.html)
- [The Dining Philosophers Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
