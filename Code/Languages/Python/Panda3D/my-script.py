'''
    Kevin Tran
    Panda3D Tutorial Chapter 1
'''

from math import pi, sin, cos

from direct.showbase.ShowBase import ShowBase
from direct.task import Task
from direct.actor.Actor import Actor


# Our class inherits from ShowBase.
class MyApp(ShowBase):

    # Panda3D contains a data structure caled the Scene Graph.
    # The Scene Graph is a tree containing all objects that need to be rendered.
    # At the root of the tree is an objected named 'render'.
    # Nothing is rendered until it is first inserted into the Scene Graph.
    # By default, Panda3D runs a task that allows you to move the camera using the mouse.
    # Left button to pan left and right
    # Right button to move forwards and backwards
    # Middle button to rotate around the origin of the application
    # Right and middle buttons to roll the point of view around the view axis
    def __init__(self):
        ShowBase.__init__(self)

        # Load the environment model.
        # ShowBase procedure loads the specified file.
        # In this case, the environment.egg file is in the models folder.
        # The return value is an object of the NodePath class, effectively
        # a pointer to the model.
        # Note that Panda Filename Syntax uses the forward-slash, even under Windows.
        self.scene = self.loader.loadModel("models/environment")

        # Reparent the model to render.
        # Install the grassy scenery model into the Scene Graph.
        self.scene.reparentTo(self.render)

        # Apply scale and position transforms on the model.
        # Use geographical coordinate system to represent map coordinates
        # (8, 42) and height 0, for instance. These coordinates are based
        # from OpenGL/Direct3D. Hold up your right hand in the classical
        # position with your thumb as X, fingers as Y, and palm as Z facing
        # toward you. Tilt backward until your hand is level with the fingers
        # pointing away and palm facing back up. Moving forward is a positive
        # change in Y coordinate.
        self.scene.setScale(0.25, 0.25, 0.25)
        self.scene.setPos(-8, 42, 0)

        # Add the spinCameraTask procedure to the task manager.
        self.taskMgr.add(self.spinCameraTask, "SpinCameraTask")

        # Load and transform the panda actor.
        self.pandaActor = Actor("models/panda-model",
                                {"walk": "models/panda-walk4"})
        self.pandaActor.setScale(0.005, 0.005, 0.005)
        self.pandaActor.reparentTo(self.render)

        # Loop its animation.
        self.pandaActor.loop("walk")


    # Define a procedure to move the camera.
    def spinCameraTask(self, task):
        # Compute the desired orientation of the camera.
        # The camera rotates 6 degrees every second.
        angleDegrees = task.time * 6.0
        angleRadians = angleDegrees * (pi / 180.0)

        # Set the position of the camera.
        self.camera.setPos(20 * sin(angleRadians), -20.0 * cos(angleRadians), 3)

        # Set the orientation.
        self.camera.setHpr(angleDegrees, 0, 0)

        # As long as this procedure returns the constant Task.cont,
        # the task manager will continue to call it every frame.
        return Task.cont

app = MyApp()

# Contains Panda3D main loop. Renders a frame, handles the background tasks,
# and then repeats. It does not normally return, so it needs to be called only
# once and must be the last line in your script.
app.run()