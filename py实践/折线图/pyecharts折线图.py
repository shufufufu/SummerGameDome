from pyecharts.charts import Line
from pyecharts.options import TitleOpts,LegendOpts,ToolboxOpts,VisualMapOpts
#创造一个折线图
line = Line()
#给x轴添加数据
line.add_xaxis(["china","the us","the uk"])
#给折线对象添加y轴数据
line.add_yaxis("GDP",[30,20,10])

#设置全局配置项set_global_opts来设置
line.set_global_opts(
    title_opts=TitleOpts(title = "GDP展示",pos_left = "center",pos_bottom="1%"),
    legend_opts=LegendOpts(is_show=True),
    toolbox_opts=ToolboxOpts(is_show=True),
    visualmap_opts=VisualMapOpts(is_show=True),
)


line.render()



