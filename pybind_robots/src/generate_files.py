import sys
import IPython



if __name__ == "__main__":
  template_file = "src/robot_wrapper.h"
  target_name = sys.argv[1]
  target_file = "src/" + target_name + "_wrapper.h"
  
  replacename =  target_name.lower()
  
  Replacename = replacename
  replacename_list = list(replacename)
  replacename_list[0] = replacename_list[0].upper()
  Replacename = ''.join(replacename_list)
  
  

  with open(template_file, "rt") as fin:
    with open(target_file, "wt") as fout:
      for line in fin:
        line = line.replace('robotname', replacename)
        line = line.replace('Robotname', Replacename)
        fout.write(line)
