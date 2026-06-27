import java.util.ArrayList;

public class Student extends Person implements Reportable {
    private String rollNumber;
    private String branch;
    private int semester;
    private ArrayList<Subject> subjects;

    public Student(String rollNumber, String name, int age, String email, String branch, int semester) {
        super(name, age, email);
        this.rollNumber = rollNumber;
        this.branch = branch;
        this.semester = semester;
        this.subjects = new ArrayList<>();
    }

    public void addSubject(Subject subject) {
        subjects.add(subject);
    }

    public double calculateTotalPercentage() {
        if (subjects.isEmpty()) return 0;
        int totalObtained = 0;
        int totalMax = 0;
        for (Subject s : subjects) {
            totalObtained += s.getMarksObtained();
            totalMax += s.getTotalMarks();
        }
        return ((double) totalObtained / totalMax) * 100;
    }

    @Override
    public String getGrade() {
        double percentage = calculateTotalPercentage();
        if (percentage >= 90) return "A+";
        else if (percentage >= 75) return "A";
        else if (percentage >= 60) return "B";
        else if (percentage >= 50) return "C";
        else if (percentage >= 40) return "D";
        else return "F";
    }

    @Override
    public boolean hasPassed() {
        for (Subject s : subjects) {
            if (s.getPercentage() < 40) return false;
        }
        return true;
    }

    @Override
    public void generateReport() {
        System.out.println("=============================");
        System.out.println("        RESULT CARD          ");
        System.out.println("=============================");
        displayInfo();
        System.out.println("-----------------------------");
        System.out.println("Subject-wise Marks:");
        for (Subject s : subjects) {
            s.displaySubject();
        }
        System.out.println("-----------------------------");
        System.out.println("Total Percentage: " + String.format("%.2f", calculateTotalPercentage()) + "%");
        System.out.println("Grade: " + getGrade());
        System.out.println("Result: " + (hasPassed() ? "PASS" : "FAIL"));
        System.out.println("=============================");
    }

    @Override
    public void displayInfo() {
        System.out.println("Roll Number: " + rollNumber);
        System.out.println("Name: " + getName());
        System.out.println("Age: " + getAge());
        System.out.println("Email: " + getEmail());
        System.out.println("Branch: " + branch);
        System.out.println("Semester: " + semester);
    }

    public String getRollNumber() { return rollNumber; }
    public String getBranch() { return branch; }
}
