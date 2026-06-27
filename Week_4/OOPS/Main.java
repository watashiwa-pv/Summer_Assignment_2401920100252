public class Main {
    public static void main(String[] args) {

        ResultManagementSystem rms = new ResultManagementSystem("ABC Institute of Technology");

        System.out.println("===== Adding Teachers =====");
        Teacher t1 = new Teacher("T001", "Dr. Sharma", 45, "sharma@abc.edu", "CSE", "Data Structures");
        Teacher t2 = new Teacher("T002", "Prof. Verma", 38, "verma@abc.edu", "CSE", "OOP");
        rms.addTeacher(t1);
        rms.addTeacher(t2);

        System.out.println();
        System.out.println("===== Adding Students =====");
        Student s1 = new Student("22CS001", "Priyanshu", 20, "priyanshu@abc.edu", "CSE", 4);
        Student s2 = new Student("22CS002", "Rahul", 20, "rahul@abc.edu", "CSE", 4);
        Student s3 = new Student("22IT001", "Neha", 21, "neha@abc.edu", "IT", 4);
        rms.addStudent(s1);
        rms.addStudent(s2);
        rms.addStudent(s3);

        System.out.println();
        System.out.println("===== Adding Marks =====");
        t1.addMarks(s1, new Subject("Data Structures", 88, 100));
        t2.addMarks(s1, new Subject("OOP", 92, 100));
        t1.addMarks(s1, new Subject("Mathematics", 78, 100));
        t2.addMarks(s1, new Subject("DBMS", 85, 100));

        t1.addMarks(s2, new Subject("Data Structures", 55, 100));
        t2.addMarks(s2, new Subject("OOP", 48, 100));
        t1.addMarks(s2, new Subject("Mathematics", 35, 100));  // below 40, will fail
        t2.addMarks(s2, new Subject("DBMS", 60, 100));

        t1.addMarks(s3, new Subject("Data Structures", 95, 100));
        t2.addMarks(s3, new Subject("OOP", 91, 100));
        t1.addMarks(s3, new Subject("Mathematics", 89, 100));
        t2.addMarks(s3, new Subject("DBMS", 94, 100));

        System.out.println();
        rms.showAllResults();

        rms.showPassFailSummary();

        System.out.println();
        rms.showToppers();

        System.out.println();
        System.out.println("===== Search Student =====");
        Student found = rms.searchStudent("22CS002");
        if (found != null) {
            found.generateReport();
        } else {
            System.out.println("Student not found.");
        }
    }
}
