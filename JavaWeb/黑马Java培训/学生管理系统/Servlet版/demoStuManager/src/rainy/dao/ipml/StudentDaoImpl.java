package rainy.dao.ipml;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Timestamp;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import javax.sql.DataSource;

import org.apache.commons.dbutils.QueryRunner;
import org.apache.commons.dbutils.ResultSetHandler;
import org.apache.commons.dbutils.handlers.BeanHandler;
import org.apache.commons.dbutils.handlers.BeanListHandler;
import org.apache.commons.dbutils.handlers.ScalarHandler;

import rainy.dao.StudentDao;
import rainy.domain.Manager;
import rainy.domain.Student;
import rainy.utils.JDBCUtils;

public class StudentDaoImpl implements StudentDao {

	@Override
	public List<Student> queryAll() {
		// 创建数据源
		DataSource ds = JDBCUtils.getDataSource();
		// 创建QueryRunner
		QueryRunner runner = new QueryRunner(ds);
		// 查询数据
		List<Student> students = new ArrayList<Student>();
		try {
			String sqlFindAll = "select * from student;";
			runner.query(sqlFindAll, new ResultSetHandler<Student>() {

				@Override
				public Student handle(ResultSet rs) throws SQLException {
					while(rs.next()) {
						Student stu = new Student();
						stu.setSid(rs.getInt("sid"));
						stu.setSname(rs.getString("sname"));
						stu.setSex(rs.getString("sex"));
						stu.setPhone(rs.getString("phone"));
						stu.setHobby(rs.getString("hobby"));
						stu.setDescript(rs.getString("descript"));
						//  因mysql的时区问题，需要转成字符串再转成Timestamp类型
						String date = rs.getString("create_time");
						if(date != null) {
							stu.setCreate_time(Timestamp.valueOf(date));
						}
						students.add(stu);
					}
					return null;
				}
				
			});
		} catch (SQLException e) {
			e.printStackTrace();
		}
		
		return students;
	}

	@Override
	public void add(Student stu) {
		DataSource ds = JDBCUtils.getDataSource();
		QueryRunner runner = new QueryRunner(ds);
		String sqlAddStu = "insert into student(sid, sname, sex, phone, hobby, descript, create_time) values(null, '" + 
		stu.getSname() + "', '" + stu.getSex() + "', '" + stu.getPhone() + "', '" +
				stu.getHobby() + "', '" + stu.getDescript() + "', current_timestamp);";
		try {
			runner.update(sqlAddStu);
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}

	@Override
	public void delete(int sid) {
		DataSource ds = JDBCUtils.getDataSource();
		QueryRunner runner = new QueryRunner(ds);
		String sqlDelStu = "delete from student where sid = ?;";
		try {
			runner.update(sqlDelStu, String.valueOf(sid));
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}

	@Override
	public Student queryById(int sid) {
		DataSource ds = JDBCUtils.getDataSource();
		QueryRunner runner = new QueryRunner(ds);
		String sqlFindStu = "select * from student where sid = " + sid + ";";
		Student stu = null;
		try {
			stu = runner.query(sqlFindStu, new BeanHandler<Student>(Student.class));
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return stu;
	}

	@Override
	public void update(Student stu) {
		DataSource ds = JDBCUtils.getDataSource();
		QueryRunner runner = new QueryRunner(ds);
		String sqlUpdateStu = "update student set sname=?, sex=?, phone=?, hobby=?, descript=? where sid=?;";
		Object[] params = {stu.getSname(), stu.getSex(), stu.getPhone(), stu.getHobby(), stu.getDescript(), stu.getSid()};
		try {
			runner.update(sqlUpdateStu, params);
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}

	@Override
	public List<Student> queryByNameAndSex(String queryByName, String queryBySex) {
		DataSource ds = JDBCUtils.getDataSource();
		QueryRunner runner = new QueryRunner(ds);
		String sqlQueryStu = "select * from student where 1 = 1 ";
		if(queryByName != null) {
			sqlQueryStu += "and sname like '%" + queryByName + "%' ";
		}
		if(queryBySex != null) {
			sqlQueryStu += "and sex='" + queryBySex + "' ";
		}
		sqlQueryStu += ";";
		List<Student> queryStudents = null;
		try {
			queryStudents = runner.query(sqlQueryStu, new BeanListHandler<Student>(Student.class));
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return queryStudents;
	}

	@Override
	public int totalItems() {
		DataSource ds = JDBCUtils.getDataSource();
		QueryRunner runner = new QueryRunner(ds);
		String sqlTotalStu = "select count(*) from student";
		Long totalItems = 0L;
		try {
			totalItems = (Long) runner.query(sqlTotalStu, new ScalarHandler());
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return totalItems.intValue();
	}

	@Override
	public List<Student> queryByPage(int currentPage) {
		DataSource ds = JDBCUtils.getDataSource();
		QueryRunner runner = new QueryRunner(ds);
		// 从第几条开始显示
		int start = (currentPage - 1) * Manager.pageSize;
		String sqlQueryStuByPage = "select * from student limit ?,?;";
		Object[] params = {start, Manager.pageSize};
		List<Student> students = null;
		try {
			students = runner.query(sqlQueryStuByPage, new BeanListHandler<Student>(Student.class), params);
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return students;
	}
}
