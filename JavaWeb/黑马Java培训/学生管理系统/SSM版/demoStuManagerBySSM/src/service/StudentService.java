package service;

import java.util.List;

import domain.PageModel;
import domain.Student;

public interface StudentService {

	PageModel query(String queryByName, String queryBySex, int currentPage);

	void add(Student stu);

	void delete(String sid);

	Student queryById(int sid);

	void update(Student stu);
	
}
