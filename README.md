# Systemy Czasu Rzeczywistego - DroneSystem

### System sterowania dronem dostarczającym przesyłki - opis
System sterowania drona pobiera przesyłkę z punktu A, ocenia wagę przesyłki. Jeśli jest odpowiednia startuje i wznosi
się na opowiednią wysokość pobraną z czujników, w przeciwnym wypadku reaguje komunikatem. Po rozpoczęciu lotu w kierunku punktu B (dostarczenia przesyłki), w  momencie uzyskania informacji o przeszkodzie powinien zwiększyć
wysokość i kontynuować lot do punktu B. Dron posiada również komunikację z nadzorem naziemnym i w przypadku uzyskania żądania od
operatora, zawraca i wraca do punktu A bez dostarczania przesyłki (np. w przypadku komunikatu o złej pogodzie).  

### Model AADL

#### Operator - główny system

![Screenshot](https://github.com/jserweta/DroneSystem/blob/master/operator_diagram.png)

#### Drone - podsystem operatora

![Screenshot](https://github.com/jserweta/DroneSystem/blob/master/drone_structure_diagram.png)
