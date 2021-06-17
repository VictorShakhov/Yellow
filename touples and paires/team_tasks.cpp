#include <iostream>
#include <map>
#include <tuple>

using namespace std;

enum class TaskStatus {
    NEW,
    IN_PROGRESS,
    TESTING,
    DONE
};

using TasksInfo = map<TaskStatus, int>;

void EraseZeros(TasksInfo& tasks) {
    for(auto it = tasks.begin(); it!=tasks.end();){
        if(it->second == 0){
            it = tasks.erase(it);
        }else{
            ++it;
        }
    }
}

class TeamTasks {
public:
    const TasksInfo& GetPersonTasksInfo(const string& person) const {
        return persons_tasks.at(person);
    }

    void AddNewTask(const string& person) {
        persons_tasks[person][TaskStatus::NEW] += 1;
    }

    tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count) {
        if(persons_tasks.find(person) == persons_tasks.end()) {
            TasksInfo A, B;
            return make_tuple(A, B);
        }
        TasksInfo updated_tasks, untouched_tasks = GetPersonTasksInfo(person);
        untouched_tasks.erase(TaskStatus::DONE);
        int i = min(task_count, untouched_tasks[TaskStatus::NEW]), tasks = task_count;
        updated_tasks[TaskStatus::IN_PROGRESS] += i;
        persons_tasks[person][TaskStatus::IN_PROGRESS] += i;
        untouched_tasks[TaskStatus::NEW] -= i;
        persons_tasks[person][TaskStatus::NEW] -= i;
        tasks -= i;
        if(tasks < 0) {
            tasks = 0;
        }
        i = min(tasks, untouched_tasks[TaskStatus::IN_PROGRESS]);
        updated_tasks[TaskStatus::TESTING] += i;
        persons_tasks[person][TaskStatus::TESTING] += i;
        untouched_tasks[TaskStatus::IN_PROGRESS] -= i;
        persons_tasks[person][TaskStatus::IN_PROGRESS] -= i;
        tasks -= i;
        if(tasks < 0) {
            tasks = 0;
        }
        i = min(tasks, untouched_tasks[TaskStatus::TESTING]);
        updated_tasks[TaskStatus::DONE] += i;
        persons_tasks[person][TaskStatus::DONE] += i;
        untouched_tasks[TaskStatus::TESTING] -= i;
        persons_tasks[person][TaskStatus::TESTING] -= i;
        EraseZeros(untouched_tasks);
        EraseZeros(updated_tasks);
        EraseZeros(persons_tasks[person]);
        return make_tuple(updated_tasks, untouched_tasks);
    }
private:
    map<string, TasksInfo> persons_tasks;
};

void PrintTasksInfo(TasksInfo tasks_info) {
    cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
        ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
        ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
        ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main() {
  TeamTasks tasks;
  tasks.AddNewTask("Ilia");
  for (int i = 0; i < 3; ++i) {
    tasks.AddNewTask("Ivan");
  }
  cout << "Ilia's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
  cout << "Ivan's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
  
  TasksInfo updated_tasks, untouched_tasks;
  
  tie(updated_tasks, untouched_tasks) =
        tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);
  
  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);

  return 0;
}


