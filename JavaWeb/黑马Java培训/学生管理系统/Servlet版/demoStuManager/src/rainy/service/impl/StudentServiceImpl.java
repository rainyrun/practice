package rainy.service.impl;

import java.util.List;

import rainy.dao.StudentDao;
import rainy.dao.ipml.StudentDaoImpl;
import rainy.domain.Manager;
import rainy.domain.Student;
import rainy.service.StudentService;

public class StudentServiceImpl implements StudentService {

	@Override
	public List<Student> queryAll() {
		// 创建学生数据对象
		StudentDao stu = new StudentDaoImpl();
		// 返回结果
		return stu.queryAll();
	}

	@Override
	public void add(Student stu) {
		// 创建学生数据对象
		StudentDao stuDao = new StudentDaoImpl();
		stuDao.add(stu);
	}

	@Override
	public void delete(int sid) {
		// 创建学生数据对象
		StudentDao stuDao = new StudentDaoImpl();
		stuDao.delete(sid);
	}

	@Override
	public Student queryById(int sid) {
		StudentDao stuDao = new StudentDaoImpl();
		return stuDao.queryById(sid);
	}

	@Override
	public void update(Student stu) {
		StudentDao stuDao = new StudentDaoImpl();
		stuDao.update(stu);
	}
	
	@Override
	public List<Student> queryByNameAndSex(String queryByName, String queryBySex) {
		// 创建查询对象
		StudentDao stuDao = new StudentDaoImpl();
		List<Student> students = stuDao.queryByNameAndSex(queryByName, queryBySex);
		return students;
	}

	@Override
	public Manager<Student> queryByNameAndSex(String queryByName, String queryBySex, int currentPage) {
		// 创建Manager
		Manager<Student> stuManager = new Manager<Student>();
		// 创建查询对象
		StudentDao stuDao = new StudentDaoImpl();
		List<Student> students = stuDao.queryByNameAndSex(queryByName, queryBySex);
		int start = (currentPage - 1) * Manager.pageSize;
		List<Student> subStus = students.subList(start, start + Manager.pageSize);
		// 设置Manager
		stuManager.setCurrentPage(currentPage);
		stuManager.setList(subStus);
		stuManager.setTotalItems(students.size());
		return stuManager;
	}

	@Override
	public int totalItems() {
		StudentDao stuDao = new StudentDaoImpl();
		return stuDao.totalItems();
	}

	@Override
	public Manager<Student> queryByPage(int currentPage) {
		// 创建Manager
		Manager<Student> stuManager = new Manager<Student>();
		// 创建查询服务
		StudentDao stuDao = new StudentDaoImpl();
		// 设置Manager
		stuManager.setCurrentPage(currentPage);
		stuManager.setTotalItems(stuDao.totalItems());
		stuManager.setList(stuDao.queryByPage(currentPage));
		
		return stuManager;
	}
}
