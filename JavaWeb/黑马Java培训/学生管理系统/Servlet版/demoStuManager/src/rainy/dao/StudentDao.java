package rainy.dao;

import java.util.List;
import rainy.domain.Student;

public interface StudentDao {
	/**
	 * 查询所有学生信息
	 * @return
	 */
	List<Student> queryAll();
	/**
	 * 添加学生
	 * @param stu 需要添加的学生的信息
	 */
	void add(Student stu);
	
	/**
	 * 删除学生
	 * @param sid 需要删除的学生sid
	 */
	void delete(int sid);
	/**
	 * 查找学生
	 * @param sid 学生的sid
	 * @return 返回找到的学生，找不到返回null
	 */
	Student queryById(int sid);
	/**
	 * 更新学生信息
	 * @param stu 学生信息
	 */
	void update(Student stu);
	/**
	 * 查询符合条件的学生
	 * @param queryByName 学生姓名包含
	 * @param queryBySex 学生性别
	 * @return 符合条件的学生
	 */
	List<Student> queryByNameAndSex(String queryByName, String queryBySex);
	/**
	 * 获取学生总数
	 * @return 学生总数
	 */
	int totalItems();
	/**
	 * 根据当前页号和每页条数，查询对应的学生信息
	 * @param currentPage 当前页号
	 * @return 本页的学生信息
	 */
	List<Student> queryByPage(int currentPage);
	
}
