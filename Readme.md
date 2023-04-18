Project#1 - Hospital System Description: The Hospital has 20 special categoies. Each patient that visits it, is assigned to a respective specilization/category. Every category has its max length/queue, up to 5 patients. Every patient has a specialization, name and status. The status could be '0'(casual) or '1'(urgent). If urgent, he is pushed in front of the queue. We create a menu, where 1) print specializations and list of patients, 2) add new patient to specialization, 3) Doctor serves a patient from a queue(and removes him) and 4) Exit the menu and Hospital.

What did I learn?

static member variables: they are declared in the class, but they must be defined outside of it, as if they were casual global variables
cin: sometimes, when reading a string(especially in a loop) problems could occur. Make sure to guard it with cin.fail() .clear() & use
