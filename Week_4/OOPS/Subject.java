public class Subject {
    private String subjectName;
    private int marksObtained;
    private int totalMarks;

    public Subject(String subjectName, int marksObtained, int totalMarks) {
        this.subjectName = subjectName;
        this.marksObtained = marksObtained;
        this.totalMarks = totalMarks;
    }

    public String getSubjectName() { return subjectName; }
    public int getMarksObtained() { return marksObtained; }
    public int getTotalMarks() { return totalMarks; }

    public double getPercentage() {
        return ((double) marksObtained / totalMarks) * 100;
    }

    public void displaySubject() {
        System.out.println(subjectName + ": " + marksObtained + "/" + totalMarks + " (" + String.format("%.2f", getPercentage()) + "%)");
    }
}
