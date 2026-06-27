public class Teacher extends Person {
    private String teacherId;
    private String department;
    private String subjectTaught;

    public Teacher(String teacherId, String name, int age, String email, String department, String subjectTaught) {
        super(name, age, email);
        this.teacherId = teacherId;
        this.department = department;
        this.subjectTaught = subjectTaught;
    }

    public void addMarks(Student student, Subject subject) {
        student.addSubject(subject);
        System.out.println("Marks added for " + student.getName() + " in " + subject.getSubjectName());
    }

    @Override
    public void displayInfo() {
        System.out.println("Teacher ID: " + teacherId);
        System.out.println("Name: " + getName());
        System.out.println("Department: " + department);
        System.out.println("Subject: " + subjectTaught);
    }
}
