cmd_/home/asus/ThucHanh/Lab2/Ex5/modules.order := {   echo /home/asus/ThucHanh/Lab2/Ex5/hello_multi.ko; :; } | awk '!x[$$0]++' - > /home/asus/ThucHanh/Lab2/Ex5/modules.order
