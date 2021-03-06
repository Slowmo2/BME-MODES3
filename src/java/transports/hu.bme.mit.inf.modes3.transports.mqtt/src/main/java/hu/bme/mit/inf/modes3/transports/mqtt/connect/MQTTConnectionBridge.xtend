package hu.bme.mit.inf.modes3.transports.mqtt.connect

import hu.bme.mit.inf.modes3.messaging.mms.messages.Message
import hu.bme.mit.inf.modes3.messaging.mms.messages.MessageType
import hu.bme.mit.inf.modes3.transports.config.TransportConfiguration
import hu.bme.mit.inf.modes3.transports.mqtt.MQTTTransport
import java.util.ArrayList
import java.util.Collections
import org.eclipse.paho.client.mqttv3.IMqttDeliveryToken
import org.eclipse.paho.client.mqttv3.MqttCallback
import org.eclipse.paho.client.mqttv3.MqttMessage
import org.eclipse.xtend.lib.annotations.Accessors
import org.slf4j.ILoggerFactory
import org.slf4j.Logger

/**
 * It stores the only MQTTClient connection that is going to be used by
 * all MQTTTransport instances in the same JVM.
 * 
 * The default topic is "modes3/all" and default QOS value is 1 (aka. at lest once).
 */
class MQTTConnectionBridge implements MqttCallback {
	@Accessors(PROTECTED_GETTER, PRIVATE_SETTER) Logger logger
	private static MQTTConnectionBridge instance

	protected val subscribers = Collections.synchronizedList(new ArrayList<MQTTTransport>)
	protected var MQTTClient client

	protected val String topic = "modes3/all"
	protected val int qos = 1

	/**
	 * The parameter config object's allEndpoints field indicates which endpoints may be brokers.
	 * 
	 * The TransportEndpoint objects' that are stored in allEndpoints indicate the connection parameters to the 
	 * respective remote brokers. Those TransportEndpoint objects' addr and pubPort fields are used only for 
	 * identification. They shall store the address of the broker (without the tcp prefix!) and the pubPort 
	 * should store the port number through which we may connect to the broker. The first successful broker 
	 * connection will be used as a broker.
	 * 
	 * If none of the allEndpoints could be connected, then it starts a broker locally on localhost. The port number
	 * is stored in config.localEndpoint's pubPort field.
	 * 
	 * The client id that will be used for identifying the connection is stored in config.localEndpoint's id field.
	 */
	private new(ILoggerFactory factory, TransportConfiguration transportConfig) {
		client = new MQTTClient(factory, transportConfig, topic, qos, this)
		logger = factory.getLogger(this.class.name)
	}

	static def getInstance(ILoggerFactory factory, TransportConfiguration transportConfig) {
		if(instance == null) {
			synchronized(MQTTConnectionBridge) {
				if(instance == null) {
					instance = new MQTTConnectionBridge(factory, transportConfig)
				}
			}
		}
		instance
	}

	def subscribe(MQTTTransport transport) {
		subscribers.add(transport)
	}

	def sendMessage(byte[] message) {
		client.sendMessage(message)
	}

	def void removeSubscriber(MQTTTransport client) {
		subscribers.remove(client)
		if(subscribers.empty) {
			this.client.close
			instance = null
		}
	}

	override connectionLost(Throwable cause) {
		logger.error("connection lost", cause)
	}

	override deliveryComplete(IMqttDeliveryToken token) {
		// left empty intentionally
	}

	override messageArrived(String topic, MqttMessage message) throws Exception {
		if(topic.equals(this.topic)) {
			try{
			val m = Message.parseFrom(message.payload)
			logger.info((m.type as MessageType).toString)
			} catch(Exception e){
				
			}
			subscribers.forEach[subs|subs.putMessage(message.payload)]
		}
	}
}
