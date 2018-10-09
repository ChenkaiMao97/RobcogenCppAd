import sys



if __name__ == "__main__":
  template_file = "robot_wrapper.h"
  target_name = sys.argv[1]
  target_file = target_name + "_wrapper.h"
  
  replacename =  target_name.lower()
  
  Replacename = replacename
  replacename[0] = replacename[0].upper()
  
  

  with open(template_file, "rt") as fin:
    with open(target_file, "wt") as fout:
      for line in fin:
        line = line.replace('robotname', replacename)
        line = line.replace('Robotname', Replacename)
        fout.write(line)
