public class calGpa {
	public static void main(String args[]) {
		Student s1 = new Student();
		Student s2 = new Student();
		Student s3 = new Student();
		s1.setStudent0("张一","数学",4,71.5);
		s1.setStudent1("张一", "英语", 3.5, 80.4);
		s1.setStudent2("张一", "数据结构", 3, 95.5);
		s2.setStudent0("李一","数学",4,78.5);
		s2.setStudent1("李一", "英语", 3.5, 54.5);
		s2.setStudent2("李一", "数据结构", 3, 60.5);
		s3.setStudent0("赵一","数学",4,88.5);
		s3.setStudent1("赵一", "英语", 3.5, 92.5);
		s3.setStudent2("赵一", "数据结构", 3, 71.5);
		System.out.println(s1.name + "的GPA为：" + s1.Gpa());
		System.out.println(s2.name + "的GPA为：" + s2.Gpa());
		System.out.println(s3.name + "的GPA为：" + s3.Gpa());
	}
}