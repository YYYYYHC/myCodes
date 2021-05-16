
public class Student {
	String name;
	String course[] = new String[3];
	double credit[] = new double[3];
	double grade[] = new double[3];
	void setStudent0(String n,String co,double cr,double g) {
		name = n;
		course[0] = co;
		credit[0] = cr;
		grade[0] = g;
	}
	void setStudent1(String n,String co,double cr,double g) {
		name = n;
		course[1] = co;
		credit[1] = cr;
		grade[1] = g;
	}
	void setStudent2(String n,String co,double cr,double g) {
		name = n;
		course[2] = co;
		credit[2] = cr;
		grade[2] = g;
	}
	double Gpa() {
		double sumg=0,sumc=0;
		for(int i=0;i<3;i++) {
			sumg += grade[i]*credit[i];
			sumc += credit[i];}
		return sumg/sumc;
	}
	
}
