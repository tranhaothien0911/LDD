cmd_/home/asus/ThucHanh/Lab2/Ex8/Consumer/modules.order := {   echo /home/asus/ThucHanh/Lab2/Ex8/Consumer/consumer.ko; :; } | awk '!x[$$0]++' - > /home/asus/ThucHanh/Lab2/Ex8/Consumer/modules.order
