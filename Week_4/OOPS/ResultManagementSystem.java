import java.util.ArrayList;

public class ResultManagementSystem {
    private String instituteName;
    private ArrayList<Student> students;
    private ArrayList<Teacher> teachers;

    public ResultManagementSystem(String instituteName) {
        this.instituteName = instituteName;
        this.students = new ArrayList<>();
        this.teachers = new ArrayList<>();
    }

    public void addStudent(Student student) {
        students.add(student);
        System.out.println("Student added: " + student.getName());
    }

    public void addTeacher(Teacher teacher) {
        teachers.add(teacher);
        System.out.println("Teacher added: " + teacher.getName());
    }

    public Student searchStudent(String rollNumber) {
        for (Student s : students) {
            if (s.getRollNumber().equals(rollNumber)) {
                return s;
            }
        }
        return null;
    }

    public void showToppers() {
        System.out.println("===== Branch-wise Toppers =====");
        ArrayList<String> branches = new ArrayList<>();
        for (Student s : students) {
            if (!branches.contains(s.getBranch())) {
                branches.add(s.getBranch());
            }
        }
        for (String branch : branches) {
            Student topper = null;
            for (Student s : students) {
                if (s.getBranch().equals(branch)) {
                    if (topper == null || s.calculateTotalPercentage() > topper.calculateTotalPercentage()) {
                        topper = s;
                    }
                }
            }
            if (topper != null) {
                System.out.println(branch + " Topper: " + topper.getName() + " (" + String.format("%.2f", topper.calculateTotalPercentage()) + "%)");
            }
        }
    }

    public void showAllResults() {
        System.out.println("===== All Results - " + instituteName + " =====");
        for (Student s : students) {
            s.generateReport();
            System.out.println();
        }
    }

    public void showPassFailSummary() {
        int passed = 0, failed = 0;
        for (Student s : students) {
            if (s.hasPassed()) passed++;
            else failed++;
        }
        System.out.println("===== Pass/Fail Summary =====");
        System.out.println("Total Students: " + students.size());
        System.out.println("Passed: " + passed);
        System.out.println("Failed: " + failed);
    }
}
