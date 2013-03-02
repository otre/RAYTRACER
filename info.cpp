#include "info.hpp"

Info::Info():
  m_core(1)
{
  countCPUCore();
}

void Info::countCPUCore(){
  pid_t pid;
  int ret;
  int tube[2];
  char buffer[512];
  std::string s;

  if(pipe(tube) == 0){
    pid =fork();
    if(pid == 0){
      close(tube[0]);
      dup2(tube[1], STDOUT_FILENO);
      execl("/bin/grep", "grep", "-c", "processor", "/proc/cpuinfo", NULL);
      exit(0);
    }
    close(tube[1]);
    ret =read(tube[0], buffer, 512);

    if(ret > 0){
      s =buffer;
      m_core =std::stol(s);
    }
  }
}
