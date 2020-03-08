package rainy.service;

import java.util.List;

import rainy.domain.Manager;
import rainy.domain.Student;

public interface StudentService {
	/**
	 * 查询所有学生
	 * @return 学生集合
	 */
	List<Student> queryAll();
	/**
	 * 添加学生
	 * @param stu 需要添加的学生
	 */
	void add(Student stu);
	
	/**
	 * 删除学生
	 * @param sid 学生编号
	 */
	void delete(int sid);
	/**
	 * 查找学生
	 * @param sid
	 * @return
	 */
	Student queryById(int sid);
	/**
	 * 更新学生信息
	 * @param stu 学生信息
	 */
	void update(Student stu);
	/**
	 * 查询满足条件的学生
	 * @param queryByName 学生姓名包含
	 * @param queryBySex 学生性别
	 * @return 学生列表
	 */
	List<Student> queryByNameAndSex(String queryByName, String queryBySex);
	/**
	 * 查询满足条件的学生，以分页形式展示
	 * @param queryByName 学生姓名包含
	 * @param queryBySex 学生性别
	 * @return 包含学生列表的Manager
	 */
	Manager<Student> queryByNameAndSex(String queryByName, String queryBySex, int currentPage);
	/**
	 * 获取学生总数
	 * @return 学生总数
	 */
	int totalItems();
	
	/**
	 * 查询当前页的学生信息
	 * @param currentPage 当前页号
	 * @param pageSize 页面含有的条数
	 * @return
	 */
	Manager<Student> queryByPage(int currentPage);
}
