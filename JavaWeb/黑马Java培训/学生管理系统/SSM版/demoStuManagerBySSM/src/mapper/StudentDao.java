package mapper;

import java.util.List;

import org.apache.ibatis.annotations.Param;

import domain.Student;

public interface StudentDao {

	int queryTotalRecords(@Param("queryByName")String queryByName, @Param("queryBySex")String queryBySex);

	List<Student> query(@Param("queryByName")String queryByName, @Param("queryBySex")String queryBySex, @Param("startIndex")int startIndex, @Param("pageSize")int pageSize);

	void add(Student stu);

	void delete(String sid);

	Student queryById(int sid);

	void update(Student stu);

}
